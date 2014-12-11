// guardar dados num ficheiro

#include <stdio.h>

adicionar livro ()
{
	FILE * pFile;
	pFile = fopen ("livrosBib.txt", "at+") 
	/* at+ -> t - para guardar a informa��o num ficheiro txt ; 
	a+ -> adicionar/atualiza��o: Abre um arquivo para atualiza��o (tanto para entrada e sa�da), 
	com todas as opera��es de sa�da de grava��o de dados no final do arquivo. 
	Opera��es de reposicionamento afeta as opera��es de entrada pr�ximos, mas as opera��es de sa�da 
	movem a posi��o de volta para o final do arquivo. O arquivo � criado se ele n�o existe. */
	if (pfile!=NULL) // se abrir ficheiro
	{
		fputs ("fopen example",pFile);
		fclose (pFile); // Fecha o arquivo 
	}
	return 0;
}
