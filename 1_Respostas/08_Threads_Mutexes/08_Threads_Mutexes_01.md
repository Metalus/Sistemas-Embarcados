1. Quais são as vantagens e desvantagens em utilizar:

(a) fork?
	Processos separados, se um travar o outro continua rodando
	
(b) threads?
	Mesmo processo rodando em 2 ou mais linhas de processamento, podem compartilhar de forma mais direta a memória entre threads
	
2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?

(a)

```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```

R:	2 Threads criadas e 2 coexistem
	O join faz esperar que cada uma termine

(b)
```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```

R:	2 Threads criadas, uma roda e depois a outra
	O join faz esperar a primeira terminar antes de iniciar a segunda

3. Apresente as características e utilidades das seguintes funções:

(a) `pthread_setcancelstate()`

R:	Seta se a Thread pode ser cancelada ou não através do pthread_cancel.

(b) `pthread_setcanceltype()`

R:	Seta o tipo de cancelamento através para receber no parâmetro no momento do pthread_cancel.

(DICA: elas são relacionadas à função pthread_cancel().)
