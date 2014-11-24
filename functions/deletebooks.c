//list of header files
#include<stdio.h>                   //contains printf,scanf etc
#include<conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include<stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
//#include<bios.h>                   //contains  show_mouse();

#define RETURNTIME 15

char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
//list of global files that can be acceed form anywhere in program
FILE *fp,*ft,*fs;

//list of global variable
int s;
char findbook;


struct meroDate
{
    int mm,dd,yy;
};
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
    struct meroDate issued;
    struct meroDate duedate;
};
struct books a;
int main()
{
      deletebooks();
      getch();
   return 0;

}


void deletebooks()    //function that delete items from file fp
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
	system("cls");
	printf("\nEnter the Book ID to  delete:");
	scanf("%d",&d);
	fp=fopen("Bibek.dat","rb+");
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	    if(a.id==d)
	    {

		printf("\nThe book record is available");
		printf("\nBook name is %s",a.name);
		printf("\nRack No. is %d",a.rackno);
		findbook='t';
	    }
	}
	if(findbook!='t')
	{
	    printf("No record is found modify the search");
	    if(getch())
	    deletebooks();
	}
	if(findbook=='t' )
	{
	    printf("Do you want to delete it?(Y/N):");
	    if(getch()=='y')
	    {
		ft=fopen("test.dat","wb+");  //temporary file for delete
		rewind(fp);
		while(fread(&a,sizeof(a),1,fp)==1)
		{
		    if(a.id!=d)
		    {
			fseek(ft,0,SEEK_CUR);
			fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
		    }                              //we want to delete
		}
		fclose(ft);
		fclose(fp);
		remove("Bibek.dat");
		rename("test.dat","Bibek.dat"); //copy all item from temporary file to fp except that
		fp=fopen("Bibek.dat","rb+");    //we want to delete
		if(findbook=='t')
		{
		    printf("\nThe record is sucessfully deleted");
		    printf("\nDelete another record?(Y/N)");
		}
	    }
	else
	deletebooks();
	fflush(stdin);
	another=getch();
	}
	}
    deletebooks();
}



void returnfunc(void)
{
    {
	printf(" Press ENTER to return to main menu");
    }
    a:
    if(getch()==13) //allow only use of enter
    deletebooks();
    else
    goto a;
}
int getdata()
{
	int t;
	printf("Enter the Information Below");
	printf("Category:");
	printf("%s",catagories[s-1]);
	printf("Book ID:\t");
	scanf("%d",&t);
	if(checkid(t) == 0)
	{
		printf("\aThe book id already exists\a");
		getch();
		deletebooks();
		return 0;
	}
	a.id=t;
	printf("Book Name:");
	scanf("%s",a.name);
	printf("Author:");
	scanf("%s",a.Author);
	printf("Quantity:");
	scanf("%d",&a.quantity);
	printf("Price:");
	scanf("%f",&a.Price);
	printf("Rack No:");
	scanf("%d",&a.rackno);
	return 1;
}
int checkid(int t)  //check whether the book is exist in library or not
{
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	if(a.id==t)
	return 0;  //returns 0 if book exits
      return 1; //return 1 if it not
}
int t(void) //for time
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}

