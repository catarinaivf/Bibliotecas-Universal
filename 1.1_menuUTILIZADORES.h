#define NR 100

typedef struct 
{
long int id_uti;   // 1 variavel da identidade do utilizador
char nome_uti[60],// 2 variavel do nome 
	 mail[60];	 // 4 variavel correio electronico
char dn[10];	// 3 variavel data nascimento
int	tele,	   // 5 variavel contacto telefonico
	estado;	  // 6 variavel do estado 0=livra 1=ocupado
}utilizador;


void ler (utilizador *x)//funcao para ler arquivo utilizador
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
	printf("Ficheiro lido <Enter para continuar>");
	getch();
}

void gravar (utilizador *x)//funcao para guardar arquivo utilizador
{
	FILE *u;
	int n;
	if (!(u=fopen("arquivos/utilizador.txt","wt")))
	{
		printf("O programa nao conseguiu abrir o arquivo <Enter para sair>");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		fprintf(u,"%ld\n",x[n].id_uti);
		fprintf(u,"%s\n",x[n].nome_uti);
		fprintf(u,"%s\n",x[n].dn);
		fprintf(u,"%s\n",x[n].mail);
		fprintf(u,"%d\n",x[n].tele);
		fprintf(u,"%d\n\n",x[n].estado);
	}
	fclose(u);
	printf("Ficheiro gravado <Enter para continuar>");
	getch();
}

void incerir(utilizador *x)//funcao para adicionar utilizador
{
	int n;
	long int inser;
	system ("cls");
	printf("ID do utilizador: ");
	scanf("%ld%*c",&inser);
	if(inser==0)
		return;
	for(n=1;n<NR;n++){//funcao para verificar validade do ID
		if(x[n].id_uti==inser){
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
		if(x[n].estado!=1)
		{
			x[n].id_uti=inser;
			printf("\nNome(nome_apelido): "); gets(x[n].nome_uti);    // scanf("%[^\n]s",x[n].nome_uti);
			printf("\nData de nascimento(DD/MM/AAAA): "); gets(x[n].dn);
			printf("\nMail: "); gets(x[n].mail);
			printf("\nNumero de telemovel/telefone: "); scanf("%d",&x[n].tele);
			x[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return;
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return;
}

int editar(utilizador *x)//funcao para editar utilizador
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o Numero do utilizador que quer Editar? "); scanf("%ld",&eli);
	for(n=1;n<NR;n++)
	{
		if(x[n].id_uti==eli)
		{
			printf("\n\nID do utilizador: %ld\nNome: %s\nData de nascimento: %s\nMail: %s\nNumero de telemovel/telefone: %d\n\n",x[n].id_uti,x[n].nome_uti,x[n].dn,x[n].mail,x[n].tele);
			fflush(stdin); 
			printf("\n%s-->",x[n].nome_uti); gets(x[n].nome_uti);    // scanf("%[^\n]s",x[n].nome_uti);
			printf("\n%s-->",x[n].dn); gets(x[n].dn);
			printf("\n%s-->",x[n].mail); gets(x[n].mail);
			printf("\n%d-->",x[n].tele); scanf("%d",&x[n].tele);


			printf("\n\n\nRegisto alterado <enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}

int eliminar(utilizador *x)
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o Numero do utilizador que quer Eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NR;n++)
	{
		if(x[n].id_uti==eli)
		{
			printf("\n\nID do utilizador: %ld\nNome: %s\nData de nascimento: %s\nMail: %s\nNumero de telemovel/telefone: %d\n\n"
			,x[n].id_uti,x[n].nome_uti,x[n].dn,x[n].mail,x[n].tele);
			printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();

			if (confere!='S' && confere!='s')    return(0);

			x[n].estado=2;
			printf("\n\n\nRegisto eliminado <enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}

void mostrar(utilizador *x)
{
	system("cls");
	int n;
	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			printf("\n\nID do utilizador: %ld\nNome: %s\nData de nascimento: %s\nMail: %s\nNumero de telemovel/telefone: %d\n\n"
			,x[n].id_uti,x[n].nome_uti,x[n].dn,x[n].mail,x[n].tele);
		}	
	}
	for(n=1;n<NR;n++)
	{
		if(x[n].estado==2)
		{
			printf("\n\nID do utilizador: %ld\nNome: %s\nData de nascimento: %s\nMail: %s\nNumero de telemovel/telefone: %d\nEliminado\n\n"
			,x[n].id_uti,x[n].nome_uti,x[n].dn,x[n].mail,x[n].tele);
		}	
	}
	
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}

void UTILIZADORES(void)// menu UTILIZADORES
{ 
		int op; // variavel a "entrar" - op
		int n;
		utilizador x;
		utilizador uti[NR];
		for(n=0;n<NR;n++)
			uti[n].estado=0;
	do{
		system("cls"); //limpa o ecrã
		//parte visual do menu*inicio
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD UTILIZADORES \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\n\t\t 1. LER ARQUIVO");
		printf("\n\t\t 2. ADICIONAR NOVO UTILIZADOR");
		printf("\n\t\t 3. APAGAR UTILIZADOR");
		printf("\n\t\t 4. EDITAR UTILIZADOR");
		printf("\n\t\t 5. LISTA");
		printf("\n\t\t 6. GRAVAR ARQUIVO");
		printf("\n\t\t 0. VOLTAR");
		printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\t\t\t:");
		//*fim
		scanf("%d", &op);	
			
		switch(op){
				case 1:
					ler(&x);
					break;
				case 2: // Se 2, vai para ADICIONAR NOVO utilizador
					incerir(&x);
					break;
				case 3:
					eliminar(&x);
					break;
				case 4:
					editar(&x);
					break;
				case 5:
					mostrar(&x);
					break;
				case 6:
					gravar(&x);	
					break;
				case 0: // Volta para o menu principal
					return;
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

