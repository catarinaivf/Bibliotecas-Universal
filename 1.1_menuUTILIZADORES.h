#define NR 100

typedef struct 
{
long int id_uti;   // 1 variavel da identidade do utilizador
char nome_uti[60],// 2 variavel do nome 
	 mail[60];	 // 4 variavel correio electronico
char dn[10];		// 3 variavel data nascimento
int	tele,	   // 5 variavel contacto telefonico
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
		fscanf(u,"%[^\n]s\n",&x[n].dn);
		fscanf(u,"%[^\n]s\n",x[n].mail);
		fscanf(u,"%d\n",&x[n].tele);
		fscanf(u,"%d\n\n",&x[n].estado);
	}
	fclose(u);
	printf("Ficheiro lido <Enter para continuar>");
	getch();
}

void LER_UTILIZADOR(void){ // Menu UTILIZADOR --> lista --> ID UTILIZADOR , após inserir o ID do UTILIZADOR
	utilizador x;
	system("cls"); // limpa o ecrã
	ler(&x);
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
		fprintf(u,"%s\n",x[n].dn);
		fprintf(u,"%s\n",x[n].mail);
		fprintf(u,"%d\n",x[n].tele);
		fprintf(u,"%d\n\n",x[n].estado);
	}
	fclose(u);
	printf("Ficheiro gravado <Enter para continuar>");
	getch();
}

void GRAVAR_UTILIZADOR(void)
{	
	utilizador x;
	system("cls");
	gravar(&x);
}

void incerir(utilizador *x)
{
	int n;
	long int inser;
	system ("cls");
	printf("ID do utilizador: ");
	scanf("%ld%*c",&inser);
	for(n=1;n<NR;n++)
	{
		if(x[n].estado!=1)
		{
			x[n].id_uti=inser;
			printf("\nNome: "); gets(x[n].nome_uti);    // scanf("%[^\n]s",x[n].nome_uti);
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

void NOVO_UTILIZADOR(void)
{
	utilizador x;
	system("cls");
	incerir(&x);
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
			printf("\n\nID do utilizador: %ld\nNome: %s\nData de nascimento: %s\nMail: %s\nNumero de telemovel/telefone: %d\nEstado: %d\n\n"
			,x[n].id_uti,x[n].nome_uti,x[n].dn,x[n].mail,x[n].tele,x[n].estado);
			printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();

			if (confere!='S' && confere!='s')    return(0);

			x[n].estado=0;
			printf("\n\n\nRegisto eliminado <enter para continuar>");
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}

void ELIMINAR_UTILIZADOR(void)
{
	utilizador x;
	system("cls");
	eliminar(&x);
}

void LISTA_Utilizadores(void)// Menu utilizadores -> Lista
{ 

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


void EDITAR_UTILIZADOR(void)// Menu UTILIZADOR -> Lista -> ID UTILIZADOR -> Editar
{ 
// como fazer para alterar as informações novas???
}

void mostrar(utilizador *x)
{
	int n;
	system ("cls");
	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			printf("\n\nID do utilizador: %ld\nNome: %s\nData de nascimento: %s\nMail: %s\nNumero de telemovel/telefone: %d\nEstado: %d\n\n"
			,x[n].id_uti,x[n].nome_uti,x[n].dn,x[n].mail,x[n].tele,x[n].estado);
		}
	}
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}

void LISTA_UTILIZADOR(void)
{
	utilizador x;
	system("cls");
	mostrar(&x);
}

void UTILIZADORES(void)// menu UTILIZADORES
{ 
		int op; // variavel a "entrar" - op

	do{
		system("cls"); //limpa o ecrã
		//parte visual do menu*inicio
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD UTILIZADORES \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\n\t\t 1. LER ARQUIVO");
		printf("\n\t\t 2. LISTA");
		printf("\n\t\t 3. ADICIONAR NOVO UTILIZADOR");
		printf("\n\t\t 4. APAGAR UTILIZADOR");
		printf("\n\t\t 5. LISTA");
		printf("\n\t\t 6. GRAVAR ARQUIVO");
		printf("\n\t\t 0. VOLTAR");
		printf("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
		printf("\n\t\t\t:");
		//*fim
		scanf("%d", &op);	
			
		switch(op){
				case 1:
					LER_UTILIZADOR();
					break;
				case 2: // Se 1, vai para menu LISTA
					LISTA_UTILIZADOR();
					break;
				case 3: // Se 2, vai para ADICIONAR NOVO utilizador
					NOVO_UTILIZADOR();
					break;
				case 4:
					ELIMINAR_UTILIZADOR();
					break;
				case 5:
					LISTA_UTILIZADOR();
					break;
				case 6:
					GRAVAR_UTILIZADOR();	
					break;
				case 0: // Volta para o menu principal
					return;
					break;
			}
			
	}while (op !=0);
	
}

