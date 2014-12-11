#define M 100 /// Numero máximo de livros a serem registados

typedef struct 
{
long int id_liv;   /// ID do Livro
char titulo[60],  /// Titulo
	 autor[60]; ///Autor
char gen[10];	///Genero
int	estado;	  //Estados dos livros : Estado=0 -> Inexistente; Estado=1 -> Existente e disponivel; Estado=2 -> Eliminado; Estado=3 -> Requisitado
}livro;


void ler_l (livro *y)//funcao para ler arquivo utilizador
{
	FILE *l;
	int n,k=0;
	if (!(l=fopen("arquivos/livro.txt","rt"))) //r- ler o ficheiro, t- ficheiro de texto
	{
		printf("O programa nao conseguiu abrir o arquivo (Prima ENTER para sair)");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		k = fscanf(l,"%ld\n",&y[n].id_liv);
		if(k==1){ /// Le apenas informaçoes que existam/estejam guardadas
			fscanf(l,"%s\n",&y[n].titulo);
			fscanf(l,"%s\n",&y[n].gen);
			fscanf(l,"%s\n",&y[n].autor);
			fscanf(l,"%d\n\n",&y[n].estado);
		}
		else
			y[n].estado=0;  /// nao e efetuada a leitura de livros com o estado a 0, pois estes são inexistentes
	}
	fclose(l);
}

void gravar_l (livro *y)//funcao para guardar arquivo livro
{
	FILE *l;
	int n;
	if (!(l=fopen("arquivos/livro.txt","wt"))) // w- escrever, t- ficheiro de texto
	{
		printf("O programa nao conseguiu abrir o arquivo (Prima ENTER para sair)");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		if(y[n].estado!=0){	// grava os livros que tenhao o estado diferente de 0, pois significa que existem
			fprintf(l,"%ld\n",y[n].id_liv);
			fprintf(l,"%s\n",y[n].titulo);
			fprintf(l,"%s\n",y[n].gen);
			fprintf(l,"%s\n",y[n].autor);
			fprintf(l,"%d\n\n",y[n].estado);
		}
	}
	fclose(l);
}

void inserir_l(livro *y)//funcao para adicionar livro
{
	
	int n;
	long int inser;
	limpa_ecra();
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  NOVO LIVRO \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
	printf("(Para continuar=1 | Para voltar=0): ");
	scanf("%ld%*c",&inser);
	if(inser==0)
		return;
	for(n=1;n<NR;n++){//funcao para verificar validade do ID
		if(y[n].id_liv!=n){ // atribuiçao automatica do ID de livro
			inser=n;
			break;	
		}
	}
	for(n=1;n<NR;n++)
	{
		if(y[n].estado!=1&&y[n].estado!=2&&y[n].estado!=3) // utiliza id's que nao estejam utilizados, pois caso tenham os estados 1, 2 ou 3 significa que ja estao utilizados/ocupados
		{
			y[n].id_liv=inser;
			printf("\nTitulo: "); gets(y[n].titulo);    // scanf("%[^\n]s",x[n].nome_uti);
			printf("\nGenero: "); gets(y[n].gen);
			printf("\nAutor: "); gets(y[n].autor);
			y[n].estado=1;
			printf("\n\n\nRegisto Inserido com sucesso! (Prima ENTER para continuar)");
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
	system("cls");
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  EDITAR LIVRO \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
	printf("\nID do livro a editar: "); scanf("%ld",&n);
		if(y[n].id_liv==n) // le o ID inserido
		{
			printf("\n\nID do livro: %ld\nTitulo: %s\nGenero: %s\nAutor: %s\n\n",y[n].id_liv,y[n].titulo,y[n].gen,y[n].autor);
			fflush(stdin); 
			printf("\n%s-->",y[n].titulo); gets(y[n].titulo);    // scanf("%[^\n]s",x[n].nome_uti);
			printf("\n%s-->",y[n].gen); gets(y[n].gen);
			printf("\n%s-->",y[n].autor); gets(y[n].autor);
			if(y[n].estado==2){
				y[n].estado=1;
				printf("\n\n\nRegisto renovado com sucesso! (Prima ENTER para continuar)");
				getch();  return (1);
			}
			else
				printf("\n\n\nRegisto alterado com sucesso! (Prima ENTER para continuar)");
				getch();  return (1);
			
		}
	printf("ERRO! Numero nao Encontrado (Prima ENTER para continuar)");
	getch(); return(0);
}

int eliminar_l(livro *y)
{
	char confere;
	int n;
	limpa_ecra();
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  ELIMINAR UTILIZADOR \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
	printf("\nID do livro a eliminar: "); scanf("%d",&n);
		if(y[n].id_liv==n){
			printf("\n\nID do livro: %ld\nTitulo: %s\nGenero: %s\nAutor: %s\n\n"
			,y[n].id_liv,y[n].titulo,y[n].gen,y[n].autor);
			if(y[n].estado!=2) // apenas para estados diferentes de 2, pois se estiverem a 2 singifica que ja estao eliminados
			{
				printf("\n\nQuer mesmo eliminar? (Sim = S | Nao = N)");confere=getch();
				if (confere!='S' && confere!='s')    return(0);
	
				y[n].estado=2; // altera o estado do livro para 2, singificando que esta eliminado
				printf("\n\n\nRegisto eliminado com sucesso! (Primo ENTER para continuar)");
				getch();  return (1);
			}
			else{
				printf("\nFoi eliminado");
				getch();  return (0);
			}
		}
		else{
			printf("ERRO! Numero nao Encontrado (Prima ENTER para continuar)");
			getch(); return(0);
		}
}

void mostrar_l(livro *y)
{
	limpa_ecra();
	int n;
	for(n=1;n<NR;n++)
	{
		
		if(y[n].estado==1) // mostra livros com estado igual a 1
		{
			printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  LISTA DE LIVROS \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
			printf("\n\nID do livro: %ld\nTitulo: %s\nGenero: %s\nAutor: %s\n\n"
			,y[n].id_liv,y[n].titulo,y[n].gen,y[n].autor);
		}	
	}
	for(n=1;n<NR;n++)
	{
		if(y[n].estado==3) // se o livro tiver o estado igual a 3, significa que esta requisitado. Apresenta o fim a informacao a dizer "requisitado"
		{
			printf("\n\nID do livro: %ld\nTitulo: %s\nGenero: %s\nAutor: %s\nRequisitado\n\n"
			,y[n].id_liv,y[n].titulo,y[n].gen,y[n].autor);
		}	
	}
	for(n=1;n<NR;n++)
	{
		if(y[n].estado==2) // se o seu estado for 2, apresenta a mensagem "eliminado"
		{
			printf("\n\nID do livro: %ld\nTitulo: %s\nGenero: %s\nAutor: %s\nEliminado\n\n"
			,y[n].id_liv,y[n].titulo,y[n].gen,y[n].autor);
		}	
	}
	
	printf("\n\n\nListagem Concluida (Prima ENTER para continuar)");getch();
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
		limpa_ecra(); //limpa o ecrã
		//parte visual do menu*inicio
		printf("\n\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD   LIVROS   \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\n\t 1. ADICIONAR NOVO LIVRO");
		printf("\n\n\t 2. APAGAR LIVRO");
		printf("\n\n\t 3. EDITAR LIVRO");
		printf("\n\n\t 4. LISTA");
		printf("\n\n\t 0. VOLTAR");
		printf("\n\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\t\t\t:");
		//*fim
		scanf("%d", &op);	
			
		switch(op){
				case 1:
					inserir_l(&y);
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
        			printf("\a\n\n\tInseriu mal opcao!Insira outra vez: ");
        			scanf("%d", &op);
        			limpa_ecra();
        		}
			}
			
	}while (op !=0);
	
}

