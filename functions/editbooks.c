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
      viewbooks();
      getch();
   return 0;

}
void viewbooks(void)  //show the list of book persists in library
{
    int i=0,j;
    system("cls");
    printf("*********************************Book List*****************************");
    printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
    j=4;
    fp=fopen("Bibek.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
	printf("%s",a.cat);
	printf("%d",a.id);
	printf("%s",a.name);
	printf("%s",a.Author);
	printf("%d",a.quantity);
	printf("%.2f",a.Price);
	printf("%d",a.rackno);
	printf("\n\n");
	j++;
	i=i+a.quantity;
      }
      printf("Total Books =%d",i);
      fclose(fp);
      returnfunc();
}
void editbooks(void)  //edit information about book
{
	system("cls");
	int c=0;
	int d,e;
	printf("****Edit Books Section****");
	char another='y';
	while(another=='y')
	{
		system("cls");
		printf("Enter Book Id to be edited:");
		scanf("%d",&d);
		fp=fopen("Bibek.dat","rb+");
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			if(checkid(d)==0)
			{
				printf("The book is availble");
				printf("The Book ID:%d",a.id);
				printf("Enter new name:");scanf("%s",a.name);
				printf("Enter new Author:");scanf("%s",a.Author);
				printf("Enter new quantity:");scanf("%d",&a.quantity);
				printf("Enter new price:");scanf("%f",&a.Price);
				printf("Enter new rackno:");scanf("%d",&a.rackno);
				printf("The record is modified");
				fseek(fp,ftell(fp)-sizeof(a),0);
				fwrite(&a,sizeof(a),1,fp);
				fclose(fp);
				c=1;
			}
			if(c==0)
			{
				printf("No record found");
			}
		}
		printf("Modify another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
	}
		returnfunc();
}
void returnfunc(void)
{
    {
	printf(" Press ENTER to return to main menu");
    }
    a:
    if(getch()==13) //allow only use of enter
    viewbooks();
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
		viewbooks();
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

