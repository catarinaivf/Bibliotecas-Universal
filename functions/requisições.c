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
      issuebooks();
      getch();
   return 0;

}

void issuebooks(void)  //function that issue books from library
{
    int t;

    system("cls");
    printf("ISSUE SECTION");
    printf("\n1. Issue a Book");
    printf("\n2. View Issued Book");
    printf("\n3. Search Issued Book");
    printf("\n4. Remove Issued Book");
    printf("Enter a Choice:");
    switch(getch())
    {
	case '1':  //issue book
	{
		system("cls");
		int c=0;
		char another='y';
		while(another=='y')
		{
			system("cls");
			printf("***Issue Book section***");
			printf("Enter the Book Id:");
			scanf("%d",&t);
			fp=fopen("Bibek.dat","rb");
			fs=fopen("Issue.dat","ab+");
			if(checkid(t)==0) //issues those which are present in library
			{
			     printf("The book record is available");
			     printf("There are %d unissued books in library ",a.quantity);
			     printf("The name of book is %s",a.name);
			     printf("Enter student name:");
			     scanf("%s",a.stname);
			    // struct dosdate_t d; //for current date
			    // _dos_getdate(&d);
			    // a.issued.dd=d.day;
			    // a.issued.mm=d.month;
			     //a.issued.yy=d.year;
			     printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
			     printf("The BOOK of ID %d is issued",a.id);
			     a.duedate.dd=a.issued.dd+RETURNTIME;   //for return date
			     a.duedate.mm=a.issued.mm;
			     a.duedate.yy=a.issued.yy;
			     if(a.duedate.dd>30)
			     {
				 a.duedate.mm+=a.duedate.dd/30;
				 a.duedate.dd-=30;

			     }
			     if(a.duedate.mm>12)
			     {
				a.duedate.yy+=a.duedate.mm/12;
				a.duedate.mm-=12;

			     }
			     printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
			     fseek(fs,sizeof(a),SEEK_END);
			     fwrite(&a,sizeof(a),1,fs);
			     fclose(fs);
			     c=1;
			}
			if(c==0)
			{
			printf("No record found");
			}
			printf("Issue any more(Y/N):");
			fflush(stdin);
			another=getche();
			fclose(fp);
		}

		break;
	}
	case '2':  //show issued book list
	{
		system("cls");
		int j=4;
		printf("*******************************Issued book list*******************************\n");
		printf("STUDENT NAME    CATEGORY    ID    BOOK NAME    ISSUED DATE    RETURN DATE");
	       fs=fopen("Issue.dat","rb");
		while(fread(&a,sizeof(a),1,fs)==1)
		{

			printf("%s",a.stname);
			printf("%s",a.cat);
			printf("%d",a.id);
			printf("%s",a.name);
			printf("%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy );
			printf("%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
			//struct dosdate_t d;
			//_dos_getdate(&d);
//			printf("Current date=%d-%d-%d",d.day,d.month,d.year);
			j++;

		}
		fclose(fs);
		returnfunc();
	}
	break;
	case '3':   //search issued books by id
	{
		system("cls");
		printf("Enter Book ID:");
		int p,c=0;
		char another='y';
		while(another=='y')
		{

			scanf("%d",&p);
			fs=fopen("Issue.dat","rb");
			while(fread(&a,sizeof(a),1,fs)==1)
			{
				if(a.id==p)
				{
					issuerecord();
					printf("Press any key.......");
					getch();
					issuerecord();
					c=1;
				}

			}
			fflush(stdin);
			fclose(fs);
			if(c==0)
			{
				printf("No Record Found");
			}
			printf("Try Another Search?(Y/N)");
			another=getch();
		}
	}
	break;
	case '4':  //remove issued books from list
	{
		system("cls");
		int b;
		FILE *fg;  //declaration of temporary file for delete
		char another='y';
		while(another=='y')
		{
			printf("Enter book id to remove:");
			scanf("%d",&b);
			fs=fopen("Issue.dat","rb+");
			while(fread(&a,sizeof(a),1,fs)==1)
			{
				if(a.id==b)
				{
					issuerecord();
					findbook='t';
				}
				if(findbook=='t')
				{
					printf("Do You Want to Remove it?(Y/N)");
					if(getch()=='y')
					{
						fg=fopen("record.dat","wb+");
						rewind(fs);
						while(fread(&a,sizeof(a),1,fs)==1)
						{
							if(a.id!=b)
							{
							fseek(fs,0,SEEK_CUR);
							fwrite(&a,sizeof(a),1,fg);
							}
						}
						fclose(fs);
						fclose(fg);
						remove("Issue.dat");
						rename("record.dat","Issue.dat");
						printf("The issued book is removed from list");

				       }

				}
				if(findbook!='t')
				{
					printf("No Record Found");
				}
			}
			printf("Delete any more?(Y/N)");
			another=getch();
		}
	}
	default:
	printf("\aWrong Entry!!");
    getch();
	issuebooks();
	break;
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
    issuebooks();
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
		issuebooks();
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

