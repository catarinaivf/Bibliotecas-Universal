#define M 100

void LISTA_LIVROS(void){ // Menu Livros -> Lista

	system("cls"); // Limpa o ecrã
	int op; // variável a "entrar" - op
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD LIVROS - Lista  \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\n\t\t ID DO LIVRO:");
	printf("\n\t\t 0. Voltar");
	scanf("%d", &op); // FALTA SABER COMO INSERIR O ID DO LIVRO E O PROGRAMA IR BUSCAR AO FICHEIRO COM OS ID'S DOS LIVROS TODOS
	
	if (op==0) // se inserir 0, volta para o menu principal
      	{
      		return;
      	}
	else // tudo o resto, vai para o menu ListaIDL - Lista - ID livro - apresenta informações
      	{
      	
      	}
	return;
	
	
}


void NOVO_LIVRO(void)  // Menu Livros -> Adicionar Novo Livro
{
	system ("cls"); // Limpa o ecrã
	char tit[M], aut[M], ed[M], gen[M]; // variaveis a entrar: titulo , autor, editora, género ; char porque vamos guardar caracteres
	printf("\t\t Titulo do Livro:");
	fflush(stdin);
	gets(tit); // 
	printf("\n\t\t Autor:");
	gets(aut);
	printf("\n\t\t Editora:");
	gets(ed);
	printf("\n\t\t Genero:");
	gets(gen);
	return;
	// FALTA SABER COMO GUARDAR AS INFORMAÇÕES
	// Falta saber como e que o sistema atribui um ID de Livro
	
}


void EDITAR_LIVRO(void){ // Menu livros -> Lista -> ID Livro -> Editar
// como fazer para alterar as informações novas???
}


void REQUISI_LIVRO(void){ // Menu Livros -> Lista -> ID LIVRO -> Requisição
	system ("cls");
	
	int IDUtili; // variavel a entrar
	printf("\n\n\t\t Inserir ID de Utilizador:");
	scanf("%d", &IDUtili);
	// falta saber como associar a requisição do livro ao utilizador
	
}

void ID_LIVRO(void){ // Menu Livros --> lista --> ID LIVRO , após inserir o ID do Livro
	system("cls"); // limpa o ecrã
	
	printf("\n\t\tTítulo:");
	// AIDICONAR PROGRAMAÇAO PARA DEVOLVER A "INFORMAÇÃO"
	printf("\n\t\t Disponibilidade:");
	// DEVOLVER A "INFORMAÇÃO"
// falta fazer como aparecer as informações relativas ao ID do Livro, deverá aparecer o Título e a Disponibilidade

	int op; // variavel a "entrar" - op
	printf("\n\n\t\t 1. REQUISICAO");
	printf("\n\n\t\t 2. EDITAR");
	printf("\n\n\t\t 0. Voltar");
	scanf("%d", &op);
	
	switch(op){
		case '1': // Se 1, vai para menu RequiL - requisição do livro
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
		int op; // variável a "entrar" - op

	do{
		system("cls"); //limpa o ecrã
		//parte visual do menu*inicio
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD LIVROS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\n\t\t 1. LISTA");
		printf("\n\t\t 2. ADICIONAR NOVO LIVRO");
		printf("\n\t\t 0. VOLTAR");
		printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\t\t\t:");
		//*fim
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
	
}

