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


void ler_u (utilizador *x)//funcao para ler arquivo utilizador
{
	FILE *u; // *u- ponteiro para o ficheiro
	int n, k=0;
	if (!(u=fopen("arquivos/utilizador.txt","rt"))) // r- para ler, t- ficheiro de texto
	{
		printf("O programa nao conseguiu abrir o arquivo (Prima ENTER para sair)");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		k = fscanf(u,"%ld\n",&x[n].id_uti);  // u, ficheiro, leitura do id de utilizacao
		if (k == 1){			 // serve para ler apenas os ficheiros existentes, para evitar leitura de "lixo"
			fscanf(u,"%s\n",&x[n].nome_uti);
			fscanf(u,"%s\n",&x[n].dn);
			fscanf(u,"%s\n",&x[n].mail);
			fscanf(u,"%d\n",&x[n].tele);
			fscanf(u,"%d\n\n",&x[n].estado);
		}
		else
			x[n].estado = 0; // se estado igual a 0, nao faz nada
	}
	fclose(u); // fechar o ficheiro
}

void gravar_u (utilizador *x)//funcao para guardar arquivo utilizador
{
	FILE *u;
	int n;
	if (!(u=fopen("arquivos/utilizador.txt","wt"))) // w- para escrever no ficheiro, t- ficheiro de texto
	{
		
		printf("O programa nao conseguiu abrir o arquivo (Prima ENTER para sair)");
		getch();
		return;
	}
	for(n=1;n<=NR;n++)
	{
		if(x[n].estado != 0){ // graa apenas utilizadores com estado diferente de 0
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
	printf("\n (Para continuar = 1 | Para voltar = 0): ");
	scanf("%ld%*c",&inser); // vai verificar se quer continuar ou nao
	if(inser==0) // se for 0, significa que o utilizador quer voltar
		return;
	for(n=1;n<NR;n++){//funcao para verificar validade do ID
		if(x[n].id_uti!=n){ // programa atribui o proprio ID  de utilizador
			inser=n;
			break;
		}
	}
	for(n=1;n<NR;n++)
	{
		if(x[n].estado!=1&&x[n].estado!=2) // para verificar se nao existe nada no espaco ocupado
		{
			x[n].id_uti=inser;
			printf("\nNome(nome_apelido): "); gets(x[n].nome_uti);    // scanf("%[^\n]s",x[n].nome_uti);
			printf("\nData de nascimento(DD/MM/AAAA): "); gets(x[n].dn);
			printf("\nMail: "); gets(x[n].mail);
			printf("\nNumero de telemovel/telefone: "); scanf("%d",&x[n].tele);
			x[n].estado=1; // coloca o estado de novos utilizadores a 1
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
		if(x[n].id_uti==n) // verificar se o ID de utilizador existe
		{
			printf("\n\nID do utilizador: %ld\nNome: %s\nData de nascimento: %s\nMail: %s\nNumero de telemovel/telefone: %d\n\n",x[n].id_uti,x[n].nome_uti,x[n].dn,x[n].mail,x[n].tele);
			fflush(stdin); 
			printf("\n%s-->",x[n].nome_uti); gets(x[n].nome_uti);    // scanf("%[^\n]s",x[n].nome_uti);
			printf("\n%s-->",x[n].dn); gets(x[n].dn);
			printf("\n%s-->",x[n].mail); gets(x[n].mail);
			printf("\n%d-->",x[n].tele); scanf("%d",&x[n].tele);
			if(x[n].estado==2){ // se o utilizador estava eliminado, e possivel editado e ele volta ao estado 1, significando que volta a estar disponivel
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
		if(x[n].id_uti==n){ // verifica de o ID de utilizador existe
			printf("\n\nID do utilizador: %ld\nNome: %s\nData de nascimento: %s\nMail: %s\nNumero de telemovel/telefone: %d\n\n"
			,x[n].id_uti,x[n].nome_uti,x[n].dn,x[n].mail,x[n].tele);
			printf("\n\nQuer mesmo eliminar? (S = Sim | N = Nao)");confere=getch();
			if(x[n].estado!=2){ // procura pelos utilizadores existentes, pois se o estado estiver a 2 significa que ja se encontra eliminado
				if (confere!='S' && confere!='s')    return(0);
	
				x[n].estado=2; //coloca o estado para 2-eliminado
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
		if(x[n].estado==1) //para mostrar utilizadores com estado a 1
		{
			printf("\n\nID de utilizador: %ld\nNome: %s\nData de nascimento: %s\nMail: %s\nNumero de telemovel/telefone: %d\n\n"
			,x[n].id_uti,x[n].nome_uti,x[n].dn,x[n].mail,x[n].tele);
		}	
	}
	for(n=1;n<NR;n++)
	{
		if(x[n].estado==2) // mostra utilizadores com estado a 2, mostrando no fim a mensagem "eliminado" . estes sao apenas mostrados no fim da lista
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
		uti[n].estado=0; // id's iniciais de utilizadores a 0, quando forem utilizados e que passam a 1
	ler_u(&x);

	do{
		system("cls"); //limpa o ecr�
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

