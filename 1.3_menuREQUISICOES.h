
#define M 100

typedef struct 
{
	long int id_uti_r,   // 1 variavel da identidade do utilizador
			id_liv_r,
			id_requisicao;
	char titulo_r[60],
		nome_r[60];
	int estado;	  // 6 variavel do estado 0=livra 1=ocupado
}requisicao;

void ler_requisicao (requisicao *z)//funcao para ler arquivo utilizador
{
	FILE *r;
	int n, k=0;

	if (!(r=fopen("arquivos/requisicao.txt","rt"))) //r- ler, t-ficheiro de texto
	{
		printf("O programa nao conseguiu abrir o arquivo (Prima ENTER para sair)");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		k=fscanf(r,"%ld\n",&z[n].id_requisicao);
		if(k==1) { // apenas le os ficheiros que existem
			fscanf(r,"%ld\n",&z[n].id_uti_r);
			fscanf(r,"%s\n",&z[n].nome_r);
			fscanf(r,"%ld\n",&z[n].id_liv_r);
			fscanf(r,"%s\n",&z[n].titulo_r);
			fscanf(r,"%d\n\n",&z[n].estado);
		}
		else
			z[n].estado = 0;
	}
	
	fclose(r);
}

void gravar_requisicao (requisicao *z)//funcao para guardar arquivo livro
{
	FILE *r;
	int n;
	if (!(r=fopen("arquivos/requisicao.txt","wt"))) // w-escrever, t- ficheiro de texto
	{
		printf("O programa nao conseguiu abrir o arquivo (Prima ENTER para sair)");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		if(z[n].estado==1||z[n].estado==2){ // guarda nas requisicoes os livros com estados a 1 e a 2
			fprintf(r,"%ld\n",z[n].id_requisicao);
			fprintf(r,"%ld\n",z[n].id_uti_r);
			fprintf(r,"%s\n",z[n].nome_r);
			fprintf(r,"%ld\n",z[n].id_liv_r);
			fprintf(r,"%s\n",z[n].titulo_r);
			fprintf(r,"%d\n\n",z[n].estado);
		}
	}
	fclose(r);
}



void mostrar_requisicao(requisicao *z)
{
	system("cls");
	printf("\n\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  LISTA DE REQUISICOES  \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	int n;
	for(n=1;n<NR;n++)
	{
		if(z[n].estado==1) // com estado a 1, significa que esta pendente, "a pessoa ainda possui o livro", requisicao ativa
		{
			printf("\n\nID da Requisicao: %ld\n%ld : %s --- %ld : %s\n\n"
			,z[n].id_requisicao,z[n].id_uti_r,z[n].nome_r,z[n].id_liv_r,z[n].titulo_r);
		}	
	}
	for(n=1;n<NR;n++)
	{
		if(z[n].estado==2) // se estado for igual a 2, significa que a requisicao ja foi concluida
		{
			printf("\n\nID da Requisicao: %ld\n%ld : %s --- %ld : %s --- Concluido\n\n"
			,z[n].id_requisicao,z[n].id_uti_r,z[n].nome_r,z[n].id_liv_r,z[n].titulo_r);
		}	
	}
	
	printf("\n\n\nListagem Concluida (Prima ENTER para Continuar)");getch();
}
	
void inserir(requisicao *z, livro *y, utilizador *x){
	int n,m;
	long int inser;
	limpa_ecra();
	printf("\n\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  NOVA REQUISICAO  \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n(Para continuar = 1 | Para voltar = 0): ");
	scanf("%ld%*c",&inser);
	if(inser==0)
		return;
	for(n=1;n<NR;n++){//funcao para verificar validade do ID
		if(z[n].id_requisicao!=n){
			inser=n;
			break;
		}
	}
	for(n=1;n<NR;n++)
	{
		//
		if(z[n].estado != 1 && z[n].estado != 2)
		{
			
			z[n].id_requisicao=inser;
			
			printf("\nID do Livro(0=voltar): "); scanf("%d",&m);    // scanf("%[^\n]s",x[n].nome_uti);
			if(inser==0)
				return;
			ler_l(y);
				if(y[m].id_liv == m){ // verifica o ID do livro e mostra o seu titulo
					printf("\nTitulo: %s",y[m].titulo);
					y[m].estado=3; // coloca o estado do livro a 3, significando que se encontra requisitado
					z[n].id_liv_r=m;
					strcpy(z[n].titulo_r,y[m].titulo);
					printf("\n\nID do Utilizador(0=voltar): "); scanf("%d",&m);
					if(inser==0)
					return;
					ler_u(x);
					if(x[m].id_uti==m){
						z[n].id_uti_r=m;
						strcpy(z[n].nome_r,x[m].nome_uti);
						z[n].estado=1; // estado da requisicao a 1, significa que esta ativa, ou pendente
						printf("\n\n\nRegisto Inserido com sucesso! (Prima ENTER para continuar)");
						getch();
						return;
					}
					break;
				}
				else
					return;
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return;

}

int concluir(requisicao *z)
{
	char confere;
	int n;
	int eli;
	system("cls");
	printf("Numero da requisicao a concluir: "); scanf("%ld",&n);
		if(z[n].id_requisicao==n){

			printf("\n\nID da Requicicao: %ld\n%ld : %s --- %ld : %s\n\n"
			,z[n].id_requisicao,z[n].id_uti_r,z[n].nome_r,z[n].id_liv_r,z[n].titulo_r);
			if(z[n].estado!=2) // verifica se o livo ja se encontra requisitado ou nao
			{
				printf("\n\nQuer mesmo eliminar? (Sim = S | Nao = N)");confere=getch();
	
				if (confere!='S' && confere!='s')    return(0);
	
				z[n].estado=2; // coloca o estado da requisicao a 2, significando que a requisicao foi concluida
				printf("\n\n\nRegisto concluida com sucesso (Prima ENTER para continuar)");
				getch();  return (1);
			}
			else{
			printf("\nFoi concluido");
			getch();  return (0);
			}
		}
		else{
			printf("ERRO! Numero nao Encontrado (Prima ENTER para continuar)");
			getch(); return(0);
		}
}

void REQUISICOES(){

	int op_REQUISICOES;//variavel opcao	
	//parte visual do menu*inicio
	int n;
	utilizador x;
	livro y;
	requisicao z;
	requisicao req[NR];
	for(n=0;n<NR;n++)
		req[n].estado=0;
	utilizador uti[NR];
	for(n=0;n<NR;n++)
		uti[n].estado=0;	
	ler_requisicao(&z);
	do{
		limpa_ecra();
		printf("\n\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  REQUISICOES \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\n\t 1. FAZER REQUISICAO");
		printf("\n\n\t 2. CONCLUIR REQUISICAO");
		printf("\n\n\t 3. LISTA REQUISICOES");
		printf("\n\n\t 0. VOLTAR");
		printf("\n\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\t\t\t:");
		//*fim
		
		scanf("%d", &op_REQUISICOES);//veja a opcao
		switch(op_REQUISICOES) {
		
			case 1: 
				inserir(&z,&y,&x); 
				break;
			case 2:	concluir(&z);break;
			case 3:	mostrar_requisicao(&z); break;
			case 0: 
				gravar_requisicao(&z);
				gravar_l(&y); 
				return;
			default:
		        printf("\a\n\n\tInseriu mal opcao!Insira outra vez: ");
		        scanf("%d", &op_REQUISICOES);
		        limpa_ecra();
	    }
	}while(1);
}

