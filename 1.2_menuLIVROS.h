#define M 100

typedef struct 
{
long int id_liv;   // 1 variavel da identidade do livro
char titulo[60],  // 2 variavel do titulo 
	 autor[60]; // 4 variavel autora
char gen[10];	// 3 variavel genero
int	tele,	   // 5 variavel contacto telefonico
	estado;	  // 6 variavel do estado 0=livra 1=ocupado
}livro;


void ler (livro *y)//funcao para ler arquivo utilizador
{
	FILE *l;
	int n;
	if (!(l=fopen("arquivos/livro.txt","rt")))
	{
		printf("O programa nao conseguiu abrir o arquivo <Enter para sair>");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		fscanf(l,"%ld\n",&y[n].id_liv);
		fscanf(l,"%s\n",&y[n].titulo);
		fscanf(l,"%s\n",&y[n].gen);
		fscanf(l,"%s\n",&y[n].autor);
		fscanf(l,"%d\n",&y[n].tele);//<-----------------------------------
		fscanf(l,"%d\n\n",&y[n].estado);
	}
	fclose(l);
	printf("Ficheiro lido <Enter para continuar>");
	getch();
}

void gravar (livro *y)//funcao para guardar arquivo livro
{
	FILE *l;
	int n;
	if (!(l=fopen("arquivos/livro.txt","wt")))
	{
		printf("O programa nao conseguiu abrir o arquivo <Enter para sair>");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		fprintf(l,"%ld\n",y[n].id_liv);
		fprintf(l,"%s\n",y[n].titulo);
		fprintf(l,"%s\n",y[n].gen);
		fprintf(l,"%s\n",y[n].autor);
		fprintf(l,"%d\n",y[n].tele);
		fprintf(l,"%d\n\n",y[n].estado);
	}
	fclose(l);
	printf("Ficheiro gravado <Enter para continuar>");
	getch();
}

void incerir(livro *y)//funcao para adicionar livro
{
	
	int n;
	long int inser;
	system ("cls");
	printf("ID do livro: ");
	scanf("%ld%*c",&inser);
	if(inser==0)
		return;
	for(n=1;n<NR;n++){//funcao para verificar validade do ID
		if(y[n].id_liv==inser){
			system ("cls");
			printf("\nID ja utilizado");
			getch();
			return;
		}
		else
			break;
	}
	for(n=1;n<NR;n++)
	{
		if(y[n].estado!=1&&y[n].estado!=2)
		{
			y[n].id_liv=inser;
			printf("\nTitulo: "); gets(y[n].titulo);    // scanf("%[^\n]s",x[n].nome_uti);
			printf("\nGenero: "); gets(y[n].gen);
			printf("\nAutor: "); gets(y[n].autor);
			printf("\nNumero de telemovel/telefone: "); scanf("%d",&y[n].tele);
			y[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return;
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return;
}

int editar(livro *y)//funcao para editar livro
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o Numero do livro que quer Editar? "); scanf("%ld",&eli);
	for(n=1;n<NR;n++)
	{
		if(y[n].id_liv==eli)
		{
			printf("\n\nID do livro: %ld\nTitulo: %s\nGenero: %s\nAutor: %s\nNumero de telemovel/telefone: %d\n\n",y[n].id_liv,y[n].titulo,y[n].gen,y[n].autor,y[n].tele);
			fflush(stdin); 
			printf("\n%s-->",y[n].titulo); gets(y[n].titulo);    // scanf("%[^\n]s",x[n].nome_uti);
			printf("\n%s-->",y[n].gen); gets(y[n].gen);
			printf("\n%s-->",y[n].autor); gets(y[n].autor);
			printf("\n%s-->",y[n].tele); scanf("%d",&y[n].tele);


			printf("\n\n\nRegisto alterado <enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}

int eliminar(livro *y)
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o Numero do livro que quer Eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NR;n++)
	{
		if(y[n].id_liv==eli)
		{
			printf("\n\nID do livro: %ld\nTitulo: %s\nGenero: %s\nAutor: %s\nNumero de telemovel/telefone: %d\n\n"
			,y[n].id_liv,y[n].titulo,y[n].gen,y[n].autor,y[n].tele);
			printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();

			if (confere!='S' && confere!='s')    return(0);

			y[n].estado=2;
			printf("\n\n\nRegisto eliminado <enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}

void mostrar(livro *y)
{
	system("cls");
	int n;
	for(n=1;n<NR;n++)
	{
		if(y[n].estado==1)
		{
			printf("\n\nID do livro: %ld\nTitulo: %s\nGenero: %s\nAutor: %s\nNumero de telemovel/telefone: %d\n\n"
			,y[n].id_liv,y[n].titulo,y[n].gen,y[n].autor,y[n].tele);
		}	
	}
	for(n=1;n<NR;n++)
	{
		if(y[n].estado==2)
		{
			printf("\n\nID do livro: %ld\nTitulo: %s\nGenero: %s\nAutor: %s\nNumero de telemovel/telefone: %d\nEliminado\n\n"
			,y[n].id_liv,y[n].titulo,y[n].gen,y[n].autor,y[n].tele);
		}	
	}
	
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}

void LIVROS(void){ // menu LIVROS
		int op; // variável a "entrar" - op
	int n;
	livro y;
	livro liv[NR];
	for(n=0;n<NR;n++)
		liv[n].estado=0;
	do{
		system("cls"); //limpa o ecrã
		//parte visual do menu*inicio
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD LIVROS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\n\t\t 1. LER ARQUIVO");
		printf("\n\t\t 2. ADICIONAR NOVO LIVRO");
		printf("\n\t\t 3. APAGAR LIVRO");
		printf("\n\t\t 4. EDITAR LIVRO");
		printf("\n\t\t 5. LISTA");
		printf("\n\t\t 6. GRAVAR ARQUIVO");
		printf("\n\t\t 0. VOLTAR");
		printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\t\t\t:");
		//*fim
		scanf("%d", &op);	
			
		switch(op){
				case 1:
					ler(&y);
					break;
				case 2: // Se 2, vai para ADICIONAR NOVO utilizador
					incerir(&y);
					break;
				case 3:
					eliminar(&y);
					break;
				case 4:
					editar(&y);
					break;
				case 5:
					mostrar(&y);
					break;
				case 6:
					gravar(&y);	
					break;
				case 0:
					return;
					break;
			}
			
	}while (op !=0);
	
}

