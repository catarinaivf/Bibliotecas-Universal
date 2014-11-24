#include <stdio.h>
#include <stdlib.h>

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
	
	case 0: return;//vem ao menu princioal
	default://se escolheu um ID
    {
        char requisicao;
		int ID_Utilizador;	
		printf("\a\n\n\tbla!bla!bla! ");
		printf("\n\tQuerfazer requisicao(s-sim/n-nao)");
		scanf("%c", &requisicao);
		if(requisicao=='s'){
			printf("Introduza o ID do utilizador");
		} else
			if(requisicao=='n')
				ID_Utilizador=0;
			else
				printf("Introduziu mal a letra");
				scanf("%c", &requisicao);
	}
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
	
	case 0: return; break;//vem ao menu princioal
	default://se escolheu um ID
        {
        char requisicao;	
		printf("\a\n\n\tbla!bla!bla! ");
		printf("\n\tQuerfazer requisicao(s-sim/n-nao)");
		scanf("%c", &requisicao);
		if(requisicao=='s'){
			printf("Introduza o ID do livro");
		} else
			if(requisicao=='n')
				ID_Utilizador=0;
			else
				printf("Introduziu mal a letra");
				scanf("%c", &requisicao);
		}
		system ("cls");
        }
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
	case 0: return; break;//vem ao menu princioal
	default://se nao foi escolodo o caso certo(pode nao sair daqui)
        {
        printf("\a\n\n\tInseriu mal opcao!Incire outra vez: ");
        scanf("%d", &op_REQUISICOES);
        system ("cls");
        }
    }
}

