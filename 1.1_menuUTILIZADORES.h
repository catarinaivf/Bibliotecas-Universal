#define M 100

void ELIMINAR (void){
}

void LISTA_Utilizadores(void){ // Menu utilizadores -> Lista

	system("cls"); // Limpa o ecr�
	int op; // vari�vel a "entrar" - op
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD Utilizadores - Lista  \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\n\t\t ID DO Utilizador:");
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


void NOVO_UTILIZADOR(void)  // Menu Livros -> Adicionar Novo Livro
{
	system ("cls"); // Limpa o ecr�
	char nome[M], mail[M]; // variaveis a entrar: nome , email ; char porque vamos guardar caracteres
	int dn[M], tel[M]; // variaveis a entrar:  Data Nascimento, Telefone; int porque vamos guardar numeros 
	printf("\t\t Utilizador:");
	fflush(stdin);
	gets(nome); // 
	printf("\n\t\t Data Nascimento:");
	scanf("%d", &dn);
	printf("\n\t\t Telefone:");
	scanf("%d", &tel);
	printf("\n\t\t Email:");
	gets(mail);
	return;
	// FALTA SABER COMO GUARDAR AS INFORMA��ES
	// Falta saber como e que o sistema atribui um ID de Livro
	
}


void EDITAR_UTILIZADOR(void){ // Menu UTILIZADOR -> Lista -> ID UTILIZADOR -> Editar
// como fazer para alterar as informa��es novas???
}


void LISTA_UTILIZADOR(void){ // Menu UTILIZADOR --> lista --> ID UTILIZADOR , ap�s inserir o ID do UTILIZADOR
	system("cls"); // limpa o ecr�
	
	printf("\n\t\tUTILIZADOR:");
	// AIDICONAR PROGRAMA�AO PARA DEVOLVER A "INFORMA��O"
	printf("\n\t\t DATA NASCIMENTO:");
	printf("\n\t\t TELEFONE:");
	printf("\n\t\t EMAIL:");
	// DEVOLVER A "INFORMA��O"
// falta fazer como aparecer as informa��es relativas ao ID do Livro, dever� aparecer o T�tulo e a Disponibilidade

	int op; // variavel a "entrar" - op
	printf("\n\n\t\t 1. EDITAR");
	printf("\n\n\t\t 2. ELIMINAR");
	printf("\n\n\t\t 0. Voltar");
	scanf("%d", &op);
	
	switch(op){
		case '1': // Se 1, vai para menu RequiL - requisi��o do livro
			EDITAR_UTILIZADOR();
			break;
		case '2': // Se 2, vai para ADICIONAR NOVO LIVRO
			ELIMINAR();
			break;
		case '0': // Volta para o menu Lista
			return;
			break;
	}while (op !=0);
}


void UTILIZADORES(void){ // menu UTILIZADORES
		int op; // vari�vel a "entrar" - op

	do{
		system("cls"); //limpa o ecr�
		//parte visual do menu*inicio
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD UTILIZADORES \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\n\t\t 1. LISTA");
		printf("\n\t\t 2. ADICIONAR NOVO UTILIZADOR");
		printf("\n\t\t 0. VOLTAR");
		printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\t\t\t:");
		//*fim
		scanf("%d", &op);	
			
		switch(op){
			
				case 1: // Se 1, vai para menu LISTA
					LISTA_UTILIZADOR();
					break;
				case 2: // Se 2, vai para ADICIONAR NOVO LIVRO
					NOVO_UTILIZADOR();
					break;
				case 0: // Volta para o menu principal
					return;
					break;
			}
			
	}while (op !=0);
	
}

