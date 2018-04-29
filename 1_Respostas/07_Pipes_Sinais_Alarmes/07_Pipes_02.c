
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char dialogo[50];
	char filho_dialogo1[] = "Pai, qual é a verdadeira essência da sabedoria ?";
	char pai_dialogo1[] = "Não façais nada violento, praticai somente aquilo que é justo e equilibrado.";
	char filho_dialogo2[] = "Mas até uma criança de três anos sabe disso!";
	char pai_dialogo2[] = "Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...";
	int fd_p[2];
	int fd_f[2];
	int i;
	pipe(fd_p);
	pipe(fd_f);
	if (fork() == 0) // filho
	{
		write(fd_f[1], filho_dialogo1, strlen(filho_dialogo1));
		read(fd_p[0], dialogo, strlen(pai_dialogo1));
		printf("PAI: %s\n", dialogo);

		write(fd_f[1], filho_dialogo2, strlen(filho_dialogo2));
		read(fd_p[0], dialogo, strlen(pai_dialogo2));
		printf("PAI: %s\n", dialogo);
	}
	else // pai
	{
		read(fd_f[0], dialogo, strlen(filho_dialogo1));
		printf("FILHO: %s\n", dialogo);
		write(fd_p[1], pai_dialogo1, strlen(pai_dialogo1));

		read(fd_f[0], dialogo, strlen(filho_dialogo2));
		printf("FILHO: %s\n", dialogo);
		write(fd_p[1], pai_dialogo2, strlen(pai_dialogo2));
	}
	return 0;
}