#define NR 100

typedef struct 
{
long int id_uti;   // 1 variavel da identidade do utilizador
char nome_uti[60],// 2 variavel do nome 
	 mail[60];	 // 4 variavel correio electronico
int dnd,dnm,dna,// 3 variaveis data nascimento dia, mes e ano
	tele,	   // 5 variavel contacto telefonico
	estado;	  // 6 variavel do estado 0=livra 1=ocupado
}utilizador;


void ler (utilizador *x)
{
	FILE *u;
	int n;
	if (!(u=fopen("arquivos/utilizador.txt","rt")))
	{
		printf("O programa nao conseguiu abrir o arquivo <Enter para sair>");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		fscanf(u,"%ld\n",&x[n].id_uti);
		fscanf(u,"%[^\n]s\n",x[n].nome_uti);
		fscanf(u,"%d %d %d\n",&x[n].dnd,&x[n].dnm,&x[n].dna);
		fscanf(u,"%[^\n]s\n",x[n].mail);
		fscanf(u,"%d\n",&x[n].tele);
		fscanf(u,"%d\n\n",&x[n].estado);
	}
	fclose(u);
	printf("Ficheiro lido <Enter para continuar>");
	getch();
}

void gravar (utilizador *x)
{
	FILE *u;
	int n;
	if (!(u=fopen("arquivos/utilizador.txt","rt")))
	{
		printf("O programa nao conseguiu abrir o arquivo <Enter para sair>");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		fprintf(u,"%ld\n",x[n].id_uti);
		fprintf(u,"%s\n",x[n].nome_uti);
		fprintf(u,"%d %d %d\n",x[n].dnd,x[n].dnm,x[n].dna);
		fprintf(u,"%s\n",x[n].mail);
		fprintf(u,"%d\n",x[n].tele);
		fprintf(u,"%d\n\n",x[n].estado);
	}
	fclose(u);
	printf("Ficheiro lido <Enter para continuar>");
	getch();
}

void ELIMINAR (void){
}

void LISTA_Utilizadores(void){ // Menu utilizadores -> Lista

	system("cls"); // Limpa o ecrã
	int op; // variável a "entrar" - op
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD Utilizadores - Lista  \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\n\t\t ID DO Utilizador:");
	printf("\n\t\t 0. Voltar");
	scanf("%d", &op); // FALTA SABER COMO INSERIR O ID DO utilizador E O PROGRAMA IR BUSCAR AO FICHEIRO COM OS ID'S DOS utilizadores 
	
	if (op==0) // se inserir 0, volta para o menu principal
      	{
      		return;
      	}
	else // tudo o resto, vai para o menu ListaIDu - Lista - ID utilizador - apresenta informações
      	{
      	
      	}
	return;
	
	
}


void NOVO_UTILIZADOR(void)  // Menu utilizador -> Adicionar Novo utilizador
{
	system ("cls"); // Limpa o ecrã
	char nome[NR], mail[NR]; // variaveis a entrar: nome , email ; char porque vamos guardar caracteres
	int dn[NR], tel[NR]; // variaveis a entrar:  Data Nascimento, Telefone; int porque vamos guardar numeros 
	printf("\t\t Utilizador:");
	fflush(stdin);
	gets(nome); 
	printf("\n\t\t Data Nascimento:");
	scanf("%d", &dn);
	printf("\n\t\t Telefone:");
	scanf("%d", &tel);
	printf("\n\t\t Email:");
	gets(mail);
	return;
	// FALTA SABER COMO GUARDAR AS INFORMAÇÕES
	// Falta saber como e que o sistema atribui um ID de utilizador
	
}


void EDITAR_UTILIZADOR(void){ // Menu UTILIZADOR -> Lista -> ID UTILIZADOR -> Editar
// como fazer para alterar as informações novas???
}


void LISTA_UTILIZADOR(void){ // Menu UTILIZADOR --> lista --> ID UTILIZADOR , após inserir o ID do UTILIZADOR

	system("cls"); // limpa o ecrã
	void ler (utilizador *x)
	
{
		
	FILE *u;
	int n;
	if (!(u=fopen("arquivos/utilizador.txt","rt")))
	{
		printf("O programa nao conseguiu abrir o arquivo <Enter para sair>");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		fscanf(u,"%ld\n",&x[n].id_uti);
		fscanf(u,"%[^\n]s\n",x[n].nome_uti);
		fscanf(u,"%d %d %d\n",&x[n].dnd,&x[n].dnm,&x[n].dna);
		fscanf(u,"%[^\n]s\n",x[n].mail);
		fscanf(u,"%d\n",&x[n].tele);
		fscanf(u,"%d\n\n",&x[n].estado);
	}
	fclose(u);
	printf("Ficheiro lido <Enter para continuar>");
	getch();
	}

}


void UTILIZADORES(void){ // menu UTILIZADORES
		int op; // variável a "entrar" - op

	do{
		system("cls"); //limpa o ecrã
		//parte visual do menu*inicio
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD UTILIZADORES \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\n\t\t 1. LISTA");
		printf("\n\t\t 2. ADICIONAR NOVO UTILIZADOR");
		printf("\n\t\t 0. VOLTAR");
		printf("\n\t\t l. ler");
		printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\t\t\t:");
		//*fim
		scanf("%d", &op);	
			
		switch(op){
				case 1: // Se 1, vai para menu LISTA
					LISTA_UTILIZADOR();
					break;
				case 2: // Se 2, vai para ADICIONAR NOVO utilizador
					NOVO_UTILIZADOR();
					break;
				case 0: // Volta para o menu principal
					return;
					break;
			}
			
	}while (op !=0);
	
}

