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
      searchbooks();
      getch();
   return 0;

}

void searchbooks()
{
    system("cls");
    int d;
    printf("*****************************Search Books*********************************");;
    printf("\n1. Search By ID");
    printf("\n2. Search By Name");
    printf("\nEnter Your Choice");
    fp=fopen("Bibek.dat","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    switch(getch())
    {
	  case '1':
	{
	    system("cls");
	    printf("****Search Books By Id****");
	    printf("\nEnter the book id:");
	    scanf("%d",&d);
	    printf("Searching........");
	    while(fread(&a,sizeof(a),1,fp)==1)
	    {
		if(a.id==d)
		{
		    delay(2);
		    printf("The Book is available");
		    printf("\nID:%d",a.id);
		    printf("\nName:%s",a.name);
		    printf("\nAuthor:%s ",a.Author);
		    printf("\nQantity:%d ",a.quantity);
		    printf("\nPrice:Rs.%.2f",a.Price);
		    printf("\nRack No:%d ",a.rackno);
		    findbook='t';
		}

	    }
	    if(findbook!='t')  //checks whether conditiion enters inside loop or not
	    {
			printf("\aNo Record Found");
	    }
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchbooks();
	    else
	    searchbooks();
	    break;
	}
	case '2':
	{
	    char s[15];
	    system("cls");
	    printf("****Search Books By Name****");
	    printf("\nEnter Book Name:");
	    scanf("%s",s);
	    int d=0;
	    while(fread(&a,sizeof(a),1,fp)==1)
	    {
		if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
		{
		    printf("The Book is available");
		    printf("\n ID:%d",a.id);
		    printf("\n Name:%s",a.name);
		    printf("\n Author:%s",a.Author);
		    printf("\n Qantity:%d",a.quantity);;
		    printf("\n Price:Rs.%.2f",a.Price);
		    printf("\n Rack No:%d ",a.rackno);

		    d++;
		}

	    }
	    if(d==0)
	    {
		printf("\aNo Record Found");
	    }
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchbooks();
	    else
	    searchbooks();
	    break;
	}
	default :
	getch();
	searchbooks();
    }
    fclose(fp);
}

void returnfunc(void)
{
    {
	printf(" Press ENTER to return to main menu");
    }
    a:
    if(getch()==13) //allow only use of enter
    searchbooks();
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
		searchbooks();
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

void issuerecord()  //display issued book's information
{
		 system("cls");
		 printf("The Book has taken by Mr. %s",a.stname);
		 printf("Issued Date:%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
		 printf("Returning Date:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
}
//End of program

