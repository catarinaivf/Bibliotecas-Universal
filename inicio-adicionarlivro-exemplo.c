// guardar dados num ficheiro

#include <stdio.h>

adicionar livro ()
{
	FILE * pFile;
	pFile = fopen ("livrosBib.txt", "at+") 
	/* at+ -> t - para guardar a informação num ficheiro txt ; 
	a+ -> adicionar/atualização: Abre um arquivo para atualização (tanto para entrada e saída), 
	com todas as operações de saída de gravação de dados no final do arquivo. 
	Operações de reposicionamento afeta as operações de entrada próximos, mas as operações de saída 
	movem a posição de volta para o final do arquivo. O arquivo é criado se ele não existe. */
	if (pfile!=NULL) // se abrir ficheiro
	{
		fputs ("fopen example",pFile);
		fclose (pFile); // Fecha o arquivo 
	}
	return 0;
}
