#include <stdio.h>
#include <stdlib.h>




void LISTA_LIVROS(void){ // Menu Livros -> Lista

	system("cls"); // Limpa o ecr�
	int op; // vari�vel a "entrar" - op
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD LIVROS - Lista  \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\n\t\t ID DO LIVRO:");
	printf("\n\t\t 0. Voltar");
	scanf("%d", &op); // FALTA SABER COMO INSERIR O ID DO LIVRO E O PROGRAMA IR BUSCAR AO FICHEIRO COM OS ID'S DOS LIVROS TODOS
	
	if (op==0) // se inserir 0, volta para o menu principal
      	{
      		return;
      	}
	else // tudo o resto, vai para o menu ListaIDL - Lista - ID livro - apresenta informa��es
      	{
      	
      	}
	return;
	
	
}


void NOVO_LIVRO(void)  // Menu Livros -> Adicionar Novo Livro
{
	system ("cls"); // Limpa o ecr�
	char tit, aut, ed, gen; // variaveis a entrar: titulo , autor, editora, g�nero ; char porque vamos guardar caracteres
	int op;
	printf("\t\t T�tulo do Livro:");
	scanf("%c", &tit); // %c por ser do tipo char, falta saber se � suposto usar o &
	printf("\n\t\t Autor:");
	scanf("%c", &aut);
	printf("\n\t\t Editora:");
	scanf("%c", &ed);
	printf("\n\t\t G�nero:");
	scanf("%c", &gen);
	
	// FALTA SABER COMO GUARDAR AS INFORMA��ES
	// Falta saber como e que o sistema atribui um ID de Livro
	
	printf("\n\n\t\t0. Voltar");
	scanf("%d", &op);
		switch(op){
		case '0':
			return;
			break;
	}while (op !=0);
}


void EDITAR_LIVRO(void){ // Menu livros -> Lista -> ID Livro -> Editar
// como fazer para alterar as informa��es novas???
}


void REQUISI_LIVRO(void){ // Menu Livros -> Lista -> ID LIVRO -> Requisi��o
	system ("cls");
	
	int IDUtili; // variavel a entrar
	printf("\n\n\t\t Inserir ID de Utilizador:");
	scanf("%d", &IDUtili);
	// falta saber como associar a requisi��o do livro ao utilizador
	
}

void ID_LIVRO(void){ // Menu Livros --> lista --> ID LIVRO , ap�s inserir o ID do Livro
	system("cls"); // limpa o ecr�
	
	printf("\n\t\tT�tulo:");
	// AIDICONAR PROGRAMA�AO PARA DEVOLVER A "INFORMA��O"
	printf("\n\t\t Disponibilidade:");
	// DEVOLVER A "INFORMA��O"
// falta fazer como aparecer as informa��es relativas ao ID do Livro, dever� aparecer o T�tulo e a Disponibilidade

	int op; // variavel a "entrar" - op
	printf("\n\n\t\t 1. REQUISICAO");
	printf("\n\n\t\t 2. EDITAR");
	printf("\n\n\t\t 0. Voltar");
	scanf("%d", &op);
	
	switch(op){
		case '1': // Se 1, vai para menu RequiL - requisi��o do livro
			REQUISI_LIVRO();
			break;
		case '2': // Se 2, vai para ADICIONAR NOVO LIVRO
			EDITAR_LIVRO();
			break;
		case '0': // Volta para o menu Lista
			return;
			break;
	}while (op !=0);
}


void LIVROS(void){ // menu LIVROS
		int op; // vari�vel a "entrar" - op

	do{
		system("cls"); //limpa o ecr�
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD LIVROS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\n \t\t 1. LISTA");
		printf("\n\t\t 2. ADICIONAR NOVO LIVRO");
			printf("\n\t\t 0. VOLTAR");
			scanf("%d", &op);	
			
		switch(op){
			
				case 1: // Se 1, vai para menu LISTA
					LISTA_LIVROS();
					break;
				case 2: // Se 2, vai para ADICIONAR NOVO LIVRO
					NOVO_LIVRO();
					break;
				case 0: // Volta para o menu principal
					return;
					break;
			}
		
	}while (op !=0);
	system ("cls");
}

