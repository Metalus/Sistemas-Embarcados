1. Quantos pipes serão criados após as linhas de código a seguir? Por quê?

(a)
```C
int pid;
int fd[2];
pipe(fd);
pid = fork();
```

R: Apenas 1 pipe

(b)
```C
int pid;
int fd[2];
pid = fork();
pipe(fd);
```

R: 2 pipes

2. Apresente mais cinco sinais importantes do ambiente Unix, além do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais são suas características e utilidades?

R:	SIGKILL - Mata o processo
	SIGHUP - Mata processos associado ao terminal caso tenha sido encerrado
	SIGQUIT - Quando CTRL+D é pressionado
	SIGILL - Instrução ilegal
	SIGSYS - Argumento incorreto na chamada da função
	

3. Considere o código a seguir:

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```

Sabendo que a função `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, quão precisos são os alarmes criados neste código? De onde vem a imprecisão? Este é um método confiável para desenvolver aplicações em tempo real?

R: A imprecisão vem de que o sistema operacional fica trocando entre os processos na CPU.
Logo vem a imprecisão da troca do processo, inviabilizando aplicação em tempo real.
