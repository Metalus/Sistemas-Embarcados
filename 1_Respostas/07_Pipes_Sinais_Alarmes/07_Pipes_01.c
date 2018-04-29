#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	int fd[2];
	int i;
	pipe(fd);
	if (fork() == 0) // filho
	{
		for (;;)
		{
			read(fd[0], &i, sizeof(int));
			printf("%d ", i);
			if (i == 10) break;
		}
	}
	else // pai
	{
		for (i = 1; i <= 10; i++)
		{
			write(fd[1], &i, sizeof(int));
			sleep(1);
		}
		sleep(1);
	}
	return 0;
}