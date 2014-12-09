#define M 100

typedef struct 
{
long int id_liv;   // 1 variavel da identidade do livro
char titulo[60],  // 2 variavel do titulo 
	 autor[60]; // 4 variavel autora
char gen[10];	// 3 variavel genero
int	estado;	  // 6 variavel do estado 0=livra 1=ocupado
}livro;


void ler_l (livro *y)//funcao para ler arquivo utilizador
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
		fscanf(l,"%d\n\n",&y[n].estado);
	}
	fclose(l);
}

void gravar_l (livro *y)//funcao para guardar arquivo livro
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
		fprintf(l,"%d\n\n",y[n].estado);
	}
	fclose(l);
}

void incerir_l(livro *y)//funcao para adicionar livro
{
	
	int n;
	long int inser;
	system ("cls");
	printf("Incira 0 para voltar: ");
	scanf("%ld%*c",&inser);
	if(inser==0)
		return;
	for(n=1;n<NR;n++){//funcao para verificar validade do ID
		if(y[n].id_liv!=n){
			inser=n;
			break;	
		}
	}
	for(n=1;n<NR;n++)
	{
		if(y[n].estado!=1&&y[n].estado!=2&&y[n].estado!=3)
		{
			y[n].id_liv=inser;
			printf("\nTitulo: "); gets(y[n].titulo);    // scanf("%[^\n]s",x[n].nome_uti);
			printf("\nGenero: "); gets(y[n].gen);
			printf("\nAutor: "); gets(y[n].autor);
			y[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return;
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return;
}

int editar_l(livro *y)//funcao para editar livro
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
			printf("\n\nID do livro: %ld\nTitulo: %s\nGenero: %s\nAutor: %s\n\n",y[n].id_liv,y[n].titulo,y[n].gen,y[n].autor);
			fflush(stdin); 
			printf("\n%s-->",y[n].titulo); gets(y[n].titulo);    // scanf("%[^\n]s",x[n].nome_uti);
			printf("\n%s-->",y[n].gen); gets(y[n].gen);
			printf("\n%s-->",y[n].autor); gets(y[n].autor);
			if(y[n].estado==2){
				y[n].estado=1;
				break;
			}
			else
				break;
			printf("\n\n\nRegisto alterado <enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}

int eliminar_l(livro *y)
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
			printf("\n\nID do livro: %ld\nTitulo: %s\nGenero: %s\nAutor: %s\n\n"
			,y[n].id_liv,y[n].titulo,y[n].gen,y[n].autor);
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

void mostrar_l(livro *y)
{
	system("cls");
	int n;
	for(n=1;n<NR;n++)
	{
		if(y[n].estado==1)
		{
			printf("\n\nID do livro: %ld\nTitulo: %s\nGenero: %s\nAutor: %s\n\n"
			,y[n].id_liv,y[n].titulo,y[n].gen,y[n].autor);
		}	
	}
	for(n=1;n<NR;n++)
	{
		if(y[n].estado==2)
		{
			printf("\n\nID do livro: %ld\nTitulo: %s\nGenero: %s\nAutor: %s\nEliminado\n\n"
			,y[n].id_liv,y[n].titulo,y[n].gen,y[n].autor);
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
	ler_l(&y);
	do{
		system("cls"); //limpa o ecrã
		//parte visual do menu*inicio
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD LIVROS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\n\t\t 1. ADICIONAR NOVO LIVRO");
		printf("\n\t\t 2. APAGAR LIVRO");
		printf("\n\t\t 3. EDITAR LIVRO");
		printf("\n\t\t 4. LISTA");
		printf("\n\t\t 0. VOLTAR");
		printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\t\t\t:");
		//*fim
		scanf("%d", &op);	
			
		switch(op){
				case 1:
					incerir_l(&y);
					break;
				case 2:
					eliminar_l(&y);
					break;
				case 3:
					editar_l(&y);
					break;
				case 4:
					mostrar_l(&y);
					break;
				case 0:
					gravar_l(&y);return;
					break;
				default://se nao foi escolodo o caso certo(pode nao sair daqui)
        		{
        			printf("\a\n\n\tInseriu mal opcao!Incire outra vez: ");
        			scanf("%d", &op);
        			system ("cls");
        		}
			}
			
	}while (op !=0);
	
}

