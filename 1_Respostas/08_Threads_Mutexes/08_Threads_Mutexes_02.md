1. Crie um programa em C que cria uma thread, e faça com que o programa principal envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para a thread, com intervalos de 1 segundo entre cada envio. Depois de o programa principal enviar o número 10, ele aguarda 1 segundo e termina a execução. A thread escreve na tela cada valor recebido, e quando ela receber o valor 10, ela termina a execução.

'''C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* func_thread(void *arg)
{
	int* fd = (int*)arg;
	int valor;

	for (;;)
	{
		read(fd[0], &valor, sizeof(int));
		printf("%d ", valor);
		if (valor == 10) break;
	}
}
int main(int argc, char *argv[])
{
	int fd[2];
	int i;
	pthread_t th;
	pipe(fd);
	pthread_create(&th, NULL, func_thread, fd);
	for (i = 1; i <= 10; i++)
	{
		write(fd[1], &i, sizeof(int));
		sleep(1);
	}
	sleep(1);

	return 0;
}
'''

2. Crie um programa em C que preenche o vetor `long int v[50000]` completamente com valores aleatórios (use a função `random()`), e que procura o valor máximo do vetor por dois métodos:

(a) Pela busca completa no vetor `v[]`;

(b) Separando o vetor em 4 partes, e usando 4 threads para cada uma encontrar o máximo de cada parte. Ao final das threads, o programa principal compara o resultado das quatro threads para definir o máximo do vetor.

Ao final do programa principal, compare os resultados obtidos pelos dois métodos.

'''C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

long int v[50000];

void* func_thread(void *arg)
{
	int i;
	int* valores = (int*)arg;
	int max_value = valores[0];
	for(i = 1; i < 12500;i++)
		max_value = valores[i] > max_value ? valores[i] : max_value;

	return (void*)max_value;
}

int main(int argc, char *argv[])
{
	int i;
	int max_mainThread;
	int max_threads;
	int max_all_threads;
	pthread_t threads[4];
	srand(time(NULL));
	for (i = 0; i < 50000; i++)
		v[i] = rand();
	max_mainThread = v[0];

	for (i = 1; i < 50000; i++)
		max_mainThread = v[i] > max_mainThread ? v[i] : max_mainThread;

	for (i = 0; i < 4; i++)
		pthread_create(&threads[i], NULL, func_thread, &v[12500 * i]);

	for (i = 0; i < 4; i++)
	{
		pthread_join(threads[i], &max_threads);
		if (i == 0)
			max_all_threads = max_threads;
		max_all_threads = max_threads > max_all_threads ? max_threads : max_all_threads;
	}

	printf("Valor maximo single thread: %d\nValor maximo 4 threads: %d", max_mainThread, max_all_threads);
	return 0;
}
'''

3. Repita o exercício anterior, mas calcule a média do vetor ao invés do valor máximo.

'''C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

long int v[50000];

void* func_thread(void *arg)
{
	int i;
	int* valores = (int*)arg;
	long int sum = 0;
	for (i = 0; i < 12500; i++)
		sum += valores[i];

	return (void*)sum;
}

int main(int argc, char *argv[])
{
	int i;
	int sum_threads;
	double media_mainThread = 0;
	double sum_all_threads = 0;
	pthread_t threads[4];
	srand(time(NULL));
	for (i = 0; i < 50000; i++)
		v[i] = rand() % 70000;


	for (i = 0; i < 50000; i++)
		media_mainThread += v[i];

	for (i = 0; i < 4; i++)
		pthread_create(&threads[i], NULL, func_thread, &v[12500 * i]);

	for (i = 0; i < 4; i++)
	{
		pthread_join(threads[i], (void**)&sum_threads);
		sum_all_threads += sum_threads;
	}

	printf("Media single thread: %lf\nMedia 4 threads: %lf", media_mainThread/50000, sum_all_threads/50000);
	return 0;
}
'''

4. Repita o exercício anterior, mas calcule a variância do vetor ao invés da média.
