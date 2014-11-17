#include <windows.h>
#include<stdio.h>                   //contains printf,scanf etc
#include<conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
#include"menuLIVROS.h"
#include"Utilizadores.h"
#include"menuREQUISICOES.h"
#include"menuGESTAO.h"
//lista das bibliotecas

#define RETURNTIME 15

void MENU_PRINCIPAL(){
int op;//variavel opcao
	do{
	//parte visual do menu*inicio
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  MENU PRINCPIAL \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n");
	printf("\n\t1. UTILIZADORES");
	printf("\n");
	printf("\n\t2. LIVROS");
	printf("\n");
	printf("\n\t3. REQUISICOES");
	printf("\n");
	printf("\n\t4. GESTAO");
	printf("\n");
	printf("\n\t0. SAIR");
	printf("\n");
	printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\t\t\t:");
	//*fim
	
	scanf("%d", &op);//veja a opcao
	system ("cls");//faz clear do ecra
	switch(op) {
	
	case 1: UTILIZADORES(); break;//vem ao menu Utilizadores
	case 2: LIVROS(); break;//vem ao menu Livros
	case 3: REQUISICOES(); break;//vem ao menu Requisi
	case 4:	GESTAO(); break;//vem ao menu Gestao
	case 0: break;//conclui a programa	
	default://se nao foi escolodo o caso certo(pode nao sair daqui)
        {
        printf("\a\n\n\tInseriu mal opcao!Incire outra vez: ");
        scanf("%d", &op);
        system ("cls");
        }
	} 
	}while (op !=0);
}






int main()
{
	MENU_PRINCIPAL();
	return 0;
}
