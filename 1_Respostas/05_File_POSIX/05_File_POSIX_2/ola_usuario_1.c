
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int idade;
    char arquivo[40];
    char buf[80];
    char nome[40];
    int f;
    printf("Digite o seu nome: ");
    scanf("%s",arquivo);
    printf("Digite a sua idade: ");
    scanf("%d",&idade);

    strcpy(nome,arquivo);
    strcat(arquivo,".txt");

    if(f = open(arquivo, O_WRONLY |O_CREAT, S_IRWXU ))
    {
        sprintf(buf,"Nome: %s\nIdade: %d\n", nome, idade);
        write(f,buf,strlen(buf));
        close(f);
    }

    return 0;
}
