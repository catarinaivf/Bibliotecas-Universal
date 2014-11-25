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
      addbooks();
      getch();
   return 0;

}

void addbooks(void)    //funtion that add books
{
	system("cls");
	int i;
	printf("SELECT CATEGOIES");
	printf("\n1. Computer");
	printf("\n2. Electronics");
	printf("\n3. Electrical");
	printf("\n4. Civil");
	printf("\n5. Mechanical");
	printf("\n6. Architecture");
	printf("\n7. Back to main menu");
	printf("\nEnter your choice:");
	scanf("%d",&s);
	if(s==7)

	addbooks() ;
	system("cls");
	fp=fopen("Bibek.txt","at+");
	if(getdata()==1)
	{
	a.cat=catagories[s-1];
	fseek(fp,0,SEEK_END);
	fwrite(&a,sizeof(a),1,fp);
	fclose(fp);
	printf("\nThe record is sucessfully saved");
	printf("\nSave any more?(Y / N):");
	if(getch()=='n')
	    addbooks();
	else
	    system("cls");
	    addbooks();
	}
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
		addbooks();
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
//void show_mouse(void) //show inactive mouse pointer in programme
//{
//union REGS in,out;
//
//       in.x.ax = 0x1;
//       int86(0x33,&in,&out);
//}

void issuerecord()  //display issued book's information
{
		 system("cls");
		 printf("The Book has taken by Mr. %s",a.stname);
		 printf("Issued Date:%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
		 printf("Returning Date:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
}
//End of program

