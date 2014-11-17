#include <windows.h>
#include<stdio.h>                   //contains printf,scanf etc
#include<conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
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

void UTILIZADORES(){
}

void LIVROS(){
}

void REQUISICOES(){
int op_REQUISICOES;//variavel opcao	
	//parte visual do menu*inicio
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  REQUISICOES \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n");
	printf("\n\t1.Livro");
	printf("\n");
	printf("\n\t2.Utilizador");
	printf("\n");
	printf("\n\t0.Menu Principal");
	printf("\n");
	printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\t\t\t:");
	//*fim
	
	scanf("%d", &op_REQUISICOES);//veja a opcao
	system ("cls");//faz clear do ecra
	switch(op_REQUISICOES) {
	
	case 1: Livro(); break;//vem ao menu livro para escolher o livro
	case 2: Utilizador(); break;//vem ao menu utilizador para escolher utilizador
	case 0: MENU_PRINCIPAL(); break;//vem ao menu princioal
	default://se nao foi escolodo o caso certo(pode nao sair daqui)
        {
        printf("\a\n\n\tInseriu mal opcao!Incire outra vez: ");
        scanf("%d", &op_REQUISICOES);
        system ("cls");
        }
    }
}
void Livro(){
int ID_Livro;//variavel do livro	
	//parte visual do menu*inicio
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  REQUISICOES \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n");
	printf("\n\tIntroduza o ID do livro(0 para voltar a menu principal)");
	printf("\n");
	printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\t\t\t:");
	//*fim
	scanf("%d", &ID_Livro);//veja a opcao
	system ("cls");//faz clear do ecra
	switch(ID_Livro) {
	
	case 0: MENU_PRINCIPAL(); break;//vem ao menu princioal
	default://se escolheu um ID
    {
        char requisicao;	
		printf("\a\n\n\tbla!bla!bla! ");
		printf("\n\tQuerfazer requisicao(s-sim/n-nao)");
		scanf("%c", &requisicao);
		if(requisicao=='s'){
			printf("Introduza o ID do utilizador");
		else
			if(requisicao=='n')
				ID_Utilizador=0;
			else
				printf("Introduziu mal a letra");
				scanf("%c", &requisicao);
	}
}
void Utilizador(){
int ID_Utilizador;//variavel de utilizador	
	//parte visual do menu*inicio
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  REQUISICOES \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n");
	printf("\n\tIntroduza o ID do utilizador(0 para voltar a menu principal)");
	printf("\n");
	printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\t\t\t:");
	//*fim
	scanf("%d", &ID_Utilizador);//veja a opcao
	system ("cls");//faz clear do ecra
	switch(ID_Utilizador) {
	
	case 0: MENU_PRINCIPAL(); break;//vem ao menu princioal
	default://se escolheu um ID
        {
        char requisicao;	
		printf("\a\n\n\tbla!bla!bla! ");
		printf("\n\tQuerfazer requisicao(s-sim/n-nao)");
		scanf("%c", &requisicao);
		if(requisicao=='s'){
			printf("Introduza o ID do livro");
		else
			if(requisicao=='n')
				ID_Utilizador=0;
			else
				printf("Introduziu mal a letra");
				scanf("%c", &requisicao);
		}
		system ("cls");
        }
	}
}

void GESTAO(){
}

int main()
{
	MENU_PRINCIPAL();
	return 0;
}
