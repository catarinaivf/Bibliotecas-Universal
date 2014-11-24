#include<stdio.h>                   //contains printf,scanf etc
#include<conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include<stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
//lista das bibliotecas principais

#include"1.1_menuUTILIZADORES.h"
#include"1.1.1_ad_u.h"//adicionar o utilizador
#include"1.1.2_ap_u.h"//apagar o utilizador
#include"1.1.3_ed_u.h"//editar o utilizador
#include"1.1.4_pr_u.h"//procurar o utilizador

#include"1.2_menuLIVROS.h"
#include"1.2.1_ad_l.h"//adicionar o livro
#include"1.2.2_ap_l.h"//apagar o livro
#include"1.2.3_ed_l.h"//editar o livro
#include"1.2.4_pr_l.h"//procurar o livro

#include"1.3_menuREQUISICOES.h"
#include"1.3.1_f_req.h"//fazer requisicao

#include"1.4_menuGESTAO.h"

#include"relogio.h"
//lista das bibliotecas de utilizador

#define RETURNTIME 15


void MENU_PRINCIPAL(){
int op;//variavel opcao
	do{
	//parte visual do menu*inicio
	system ("cls");
	t();
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
