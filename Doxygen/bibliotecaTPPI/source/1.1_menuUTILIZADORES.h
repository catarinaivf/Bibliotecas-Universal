#define NR 100 /// Numero máximo de registos de utilizadores

typedef struct 
{
long int id_uti;    /// ID do utilizador
char nome_uti[60],	/// Nome do Utilizador
	 mail[60];		///Email do utilizador
char dn[10];	/// Data de Nascimento
int	tele,	   	/// Telefone/Telemóvel
	estado;	   /// Estado=0 -> Não existe ; Estado=1 -> Existe ; Estado=2 -> Eliminado
}utilizador;  


void ler_u (utilizador *x)//funcao para ler arquivo utilizador
{
	FILE *u; // *u- ponteiro para o ficheiro
	int n, k=0;
	if (!(u=fopen("arquivos/utilizador.txt","rt"))) /// Para abrir o ficheiro é utilizado "rt", que significa r-read e t-ficheiro de texto 
	{
		printf("O programa nao conseguiu abrir o arquivo (Prima ENTER para sair)");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		k = fscanf(u,"%ld\n",&x[n].id_uti);  /// O programa efetua a leitura no ficheito utilizadores.txt e lê as informações de ID's
		if (k == 1){			 
			fscanf(u,"%s\n",&x[n].nome_uti); /// de utilizadores que existam.
			fscanf(u,"%s\n",&x[n].dn);	
			fscanf(u,"%s\n",&x[n].mail);	
			fscanf(u,"%d\n",&x[n].tele);	
			fscanf(u,"%d\n\n",&x[n].estado);
		}
		else
			x[n].estado = 0; /// Se o estado de algum utilizador for igual a 0 o programa nao o le, pois significa que nao existe
	}
	fclose(u); 
}

void gravar_u (utilizador *x)//funcao para guardar arquivo utilizador
{
	FILE *u;
	int n;
	if (!(u=fopen("arquivos/utilizador.txt","wt"))) /// Para abrir o programa e utilizado "wt": w- para escrever no ficheiro, t- ficheiro de texto
	{
		
		printf("O programa nao conseguiu abrir o arquivo (Prima ENTER para sair)");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		if(x[n].estado != 0){ /// O programa grava apenas utilizadores com estado diferente de 0, pois caso tal aconteca, os utilizadores nao existem
			fprintf(u,"%ld\n",x[n].id_uti);	
			fprintf(u,"%s\n",x[n].nome_uti);
			fprintf(u,"%s\n",x[n].dn);
			fprintf(u,"%s\n",x[n].mail);
			fprintf(u,"%d\n",x[n].tele);
			fprintf(u,"%d\n\n",x[n].estado);
		}
	}
	fclose(u);
}

void inserir_u(utilizador *x)//funcao para adicionar utilizador
{
	int n;
	long int inser;
	limpa_ecra();
	printf("\n\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  ADICIONAR NOVO UTILIZADOR \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
	printf("\n (Para continuar = 1 | Para voltar = 0): "); /// Se o utilizador nao pretender inserir um novo utilizador, basta inserir 0 para voltar.
	scanf("%ld%*c",&inser); 
	if(inser==0) 
		return;
	for(n=1;n<NR;n++){/// É feita uma funcao que faz a atribuicao automatica dos ID's de utilizador.
		if(x[n].id_uti!=n){ 
			inser=n;
			break;
		}
	}
	for(n=1;n<NR;n++)
	{
		if(x[n].estado!=1&&x[n].estado!=2) /// Verifica se o ID inicial se encontra disponivel verificando o seu estado, se nao estiver, "avança mais um numero" até que encontre um disponivel
		{
			x[n].id_uti=inser;
			printf("\nNome(nome_apelido): "); gets(x[n].nome_uti);   
			printf("\nData de nascimento(DD/MM/AAAA): "); gets(x[n].dn);	
			printf("\nMail: "); gets(x[n].mail);	
			printf("\nNumero de telemovel/telefone: "); scanf("%d",&x[n].tele);	
			x[n].estado=1; /// Apos receber as informações, o programa coloca o estado de novos utilizadores a 1 (existente)
			printf("\n\n\nRegisto Inserido com sucesso! (Prima ENTER para Continuar)");
			getch();
			return;
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return;
}

int editar_u(utilizador *x)//funcao para editar utilizador
{
	char confere;
	int n;
	system("cls");
	printf("\n\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  EDITAR UTILIZADOR \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
	printf("ID do utilizador a editar: "); scanf("%ld",&n);
		if(x[n].id_uti==n) /// O programa verifica se o ID de utilizador existe e, se sim, procese às edições das informações.
		{
			printf("\n\nID do utilizador: %ld\nNome: %s\nData de nascimento: %s\nMail: %s\nNumero de telemovel/telefone: %d\n\n",x[n].id_uti,x[n].nome_uti,x[n].dn,x[n].mail,x[n].tele);
			fflush(stdin); 
			printf("\n%s-->",x[n].nome_uti); gets(x[n].nome_uti);    // scanf("%[^\n]s",x[n].nome_uti);
			printf("\n%s-->",x[n].dn); gets(x[n].dn);
			printf("\n%s-->",x[n].mail); gets(x[n].mail);
			printf("\n%d-->",x[n].tele); scanf("%d",&x[n].tele);
			if(x[n].estado==2){ /// SEe o utilizador estava eliminado, e possivel editado e ele volta ao estado 1, significando que volta a estar disponivel
				x[n].estado=1;
				printf("\n\n\nRegisto renovado com sucesso! (Prima ENTER para continuar)");
				getch();  return (1);
			}
			else
				printf("\n\n\nRegisto alterado com sucesso! (Prima ENTER para continuar)");
				getch();  return (1);
			
		}
		else
			printf("ERRO! Numero nao Encontrado (Prima ENTER para Continuar)");
			getch(); return(0);
}

int eliminar_u(utilizador *x)
{
	char confere;
	int n;
	limpa_ecra();
	printf("\n\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  ELIMINAR UTILIZADOR \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
	printf("ID do utilizador a Eliminar: "); scanf("%d",&n);
		if(x[n].id_uti==n){ /// verifica de o ID de utilizador existe
			printf("\n\nID do utilizador: %ld\nNome: %s\nData de nascimento: %s\nMail: %s\nNumero de telemovel/telefone: %d\n\n"
			,x[n].id_uti,x[n].nome_uti,x[n].dn,x[n].mail,x[n].tele);
			printf("\n\nQuer mesmo eliminar? (S = Sim | N = Nao)");confere=getch();
			if(x[n].estado!=2){ /// Procura pelos utilizadores existentes, pois se o estado estiver a 2 significa que ja se encontra eliminado.
				if (confere!='S' && confere!='s')    return(0);
	
				x[n].estado=2; ///Se nao estiver eliminado, altera entao o estado para 2.
				printf("\n\n\nRegisto eliminado com sucesso! (Prima ENTER para continuar)");
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

void mostrar_u(utilizador *x)
{
	system("cls");
	int n;
	printf("\n\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  LISTA DE UTILIZADORES \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1) /// Mostrar utilizadores com estado a 1
		{
			printf("\n\nID de utilizador: %ld\nNome: %s\nData de nascimento: %s\nMail: %s\nNumero de telemovel/telefone: %d\n\n"
			,x[n].id_uti,x[n].nome_uti,x[n].dn,x[n].mail,x[n].tele);
		}	
	}
	for(n=1;n<NR;n++)
	{
		if(x[n].estado==2) /// Se existirem utilizadores com estado=2, significa que estao eliminados e, como tal, mostra no fim a mensagem "eliminado" . Estes sao apenas mostrados no fim da lista.
		{
			printf("\n\nID de utilizador: %ld\nNome: %s\nData de nascimento: %s\nMail: %s\nNumero de telemovel/telefone: %d\nEliminado\n\n"
			,x[n].id_uti,x[n].nome_uti,x[n].dn,x[n].mail,x[n].tele);
		}	
	}
	
	printf("\n\n\nListagem Concluida (Prima ENTER para Continuar)");getch();
}

void UTILIZADORES(void)// menu UTILIZADORES
{ 
	int op; // variavel a "entrar" - op
	int n;
	utilizador x;
	utilizador uti[NR]; // vetor do tamanho dos utilizadores. NR definido como 100- possibilidade de registo de 100 utilizadores
	for(n=0;n<NR;n++)
		uti[n].estado=0; /// id's iniciais de utilizadores apresentam estado igual a 0, quando forem utilizados passam a 1
	ler_u(&x);

	do{
		system("cls"); //limpa o ecrã
		//parte visual do menu*inicio
		printf("\n\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  UTILIZADORES  \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\n\t 1. ADICIONAR NOVO UTILIZADOR");
		printf("\n\n\t 2. APAGAR UTILIZADOR");
		printf("\n\n\t 3. EDITAR UTILIZADOR");
		printf("\n\n\t 4. LISTA");
		printf("\n\n\t 0. VOLTAR");
		printf("\n\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\t\t\t:");
		//*fim
		scanf("%d", &op);	
			
		switch(op){
				case 1:
					inserir_u(&x);
					break;
				case 2:
					eliminar_u(&x);
					break;
				case 3:
					editar_u(&x);
					break;
				case 4:
					mostrar_u(&x);
					break;
				case 0:
					gravar_u(&x);return;
					break;
				default:
        		{
        			printf("\a\n\n\tInseriu mal opcao!Insira outra vez: ");
        			scanf("%d", &op);
        			limpa_ecra();
        		}
			}
			
	}while (op !=0);
	
}

