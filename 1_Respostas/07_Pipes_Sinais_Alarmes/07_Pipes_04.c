#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int fd[2];
	char nome[30];
	char c[30] = { 0 };
	int size;
	pipe(fd);
	if (fork() == 0) // filho
	{
		printf("Digite o nome de usuario: ");
		scanf("%s", nome);
		size = strlen(nome);
		write(fd[1], &size, sizeof(int));
		write(fd[1], nome, size);
		//nome[0] = '\0';
	}
	else // pai
	{
		read(fd[0], &size, sizeof(int));
		read(fd[0], c, size);
		printf("PAI: Nome de usuario digitado: %s", c);
	}
	return 0;
}