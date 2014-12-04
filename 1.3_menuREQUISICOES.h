/*
#define M 100

typedef struct 
{
long int id_uti_r,   // 1 variavel da identidade do utilizador
		id_uti_2,	// conatante para gravar ID utilizador
		id_liv_r,
		id_liv_2,	//constante para gravar ID livro
		id_requisicao;
int estado;	  // 6 variavel do estado 0=livra 1=ocupado
}requisicao;

void ler_utilizador(utilizador *x)//funcao para ler arquivo utilizador
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
		fscanf(u,"%s\n",&x[n].nome_uti);
		fscanf(u,"%s\n",&x[n].dn);
		fscanf(u,"%s\n",&x[n].mail);
		fscanf(u,"%d\n",&x[n].tele);
		fscanf(u,"%d\n\n",&x[n].estado);
	}
	fclose(u);
}

void ler_livro(livro *y)//funcao para ler arquivo utilizador
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

void gravar_livro(livro *y)//funcao para guardar arquivo livro
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
	printf("Ficheiro gravado <Enter para continuar>");
	getch();
}

void ler_requisicao (requisicao *z)//funcao para ler arquivo utilizador
{
	FILE *r;
	int n;
	if (!(r=fopen("arquivos/requisicao.txt","rt")))
	{
		printf("O programa nao conseguiu abrir o arquivo <Enter para sair>");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		fscanf(r,"%ld\n",z[n].id_requisicao);
		fscanf(r,"%ld\n",z[n].id_uti_r);
		fscanf(r,"%ld\n",z[n].id_liv_r);
		fscanf(r,"%d\n\n",z[n].estado);
	}
	fclose(r);
	printf("Ficheiro lido <Enter para continuar>");
	getch();
}

void gravar_requisicao (requisicao *z)//funcao para guardar arquivo livro
{
	FILE *r;
	int n;
	if (!(r=fopen("arquivos/requisicao.txt","wt")))
	{
		printf("O programa nao conseguiu abrir o arquivo <Enter para sair>");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		fprintf(r,"%ld\n",&z[n].id_requisicao);
		fprintf(r,"%ld\n",&z[n].id_uti_r);
		fprintf(r,"%ld\n",&z[n].id_liv_r);
		fprintf(r,"%d\n\n",&z[n].estado);
	}
	fclose(r);
	printf("Ficheiro gravado <Enter para continuar>");
	getch();
}



void mostrar_requisicao(requisicao *z)
{
	system("cls");
	int n;
	for(n=1;n<NR;n++)
	{
		if(z[n].estado==1)
		{
			printf("\n\nID da Requicicao: %ld\nID utilizador: %ld --- Genero: %ld\n\n"
			,z[n].id_requisicao,z[n].id_uti_r,z[n].id_liv_r);
		}	
	}
	for(n=1;n<NR;n++)
	{
		if(z[n].estado==1)
		{
			printf("\n\nID da Requicicao: %ld\nID utilizador: %ld --- Genero: %ld\nConcluido\n\n"
			,z[n].id_requisicao,z[n].id_uti_r,z[n].id_liv_r);
		}	
	}
	
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}
	
void inserir(requisicao *z){
	int n,m;
	long int inser;
	system ("cls");
	printf("ID da Requisicao: ");
	scanf("%ld%*c",&inser);
	if(inser==0)
		return;
	for(n=1;n<NR;n++){//funcao para verificar validade do ID
		if(z[n].id_requisicao==inser){
			system ("cls");
			printf("\nID utilizado");
			getch();
			return;
		}
		else
			break;
	}
	for(n=1;n<NR;n++)
	{
		if(z[n].estado!=1&&z[n].estado!=2)
		{
			z[n].id_requisicao=inser;
			ler_livro(&y);
			printf("\nID do Livro(0=voltar): "); scanf("%d",&inser);    // scanf("%[^\n]s",x[n].nome_uti);
			if(inser==0)
				return;
			for(m=1;m<NR;m++){//funcao para verificar validade do ID
				if(y[m].id_liv==inser){
				system ("cls");
				printf("\nTitulo:",y[m].titulo);
				y[m].estado=3;
				z[n].id_liv_r=inser;
				break;
				}
				else
					return;
			}
	}
			ler_utilizador(&x);
			printf("\nID do Utilizador(0=voltar): "); scanf("%d",&inser);
			if(inser==0)
				return;
			for(m=1;m<NR;m++){//funcao para verificar validade do ID
				if(x[m].id_uti==inser){
				system ("cls");
				z[n].id_uti_r=inser;
				break;
				}
				else
					return;
			z[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return;
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return;

}
*/
void REQUISICOES(){
/*

	int op_REQUISICOES;//variavel opcao	
	//parte visual do menu*inicio
		int n;
		utilizador x;
		livro y;
		requisicao z;
		requisicao req[NR];
		for(n=0;n<NR;n++)
			req[n].estado=0;
	system ("cls");
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD  REQUISICOES \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\n\t\t 1. LER ARQUIVO");
	printf("\n\t\t 2. FAZER REQUISICAO");
	printf("\n\t\t 3. CONCLUIR REQUISICAO");
	printf("\n\t\t 4. LISTA REQUISICOES");
	printf("\n\t\t 5. GRAVAR ARQUIVO");
	printf("\n\t\t 0. VOLTAR");
	printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\t\t\t:");
	//*fim
	
	scanf("%d", &op_REQUISICOES);//veja a opcao
	system ("cls");//faz clear do ecra
	switch(op_REQUISICOES) {
	
	case 1: ler_requisicao(&z); break;
	case 2: inserir(&z); break;
	case 3:	break;
	case 4:	mostrar_requisicao(&z); break;
	case 5: gravar_requisicao(&z);gravar_livro(&y); break;
	case 0: return; break;
	default:
        {
        printf("\a\n\n\tInseriu mal opcao!Incire outra vez: ");
        scanf("%d", &op_REQUISICOES);
        system ("cls");
        }
    }
*/
}

