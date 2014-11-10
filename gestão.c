void GESTAO(void){ // Menu Gestão

	system("cls"); //limpa o ecrã
	int op; // variável a "entrar" - op
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD GESTAO \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	printf("\n\n\t\t 1. LIVROS MAIS REQUISITADOS");
	printf("\n\t\t 2. UTILIZADORES MAIS FREQUENTES");
	printf("\n\t\t 3. FAIXAS ETARIAS");
	printf("\n\t\t 0. Voltar")
	
	scanf("%d", %op);

	{
		case '1': // Se 1 vai para Livros Mais Frequentes
			GESTAO_LIVROS();
			break;
		case '2': // Se 2 vai para Utilizadores mais frequentes
			GESTAO_UTILI();
			break;
		case '3': // Se 3 vai para Faixas Etárias
			GESTAO_FAIXAS();
			break;
		case '0': // volta para o menu Livros
			LIVROS();
			break;
		
		
	}
}
