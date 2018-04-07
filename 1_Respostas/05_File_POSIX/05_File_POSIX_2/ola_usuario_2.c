#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    int idade;
    char arquivo[40];
    char buf[80];
    char nome[40];
    int f;

    if(argc >=2)
    {
        strcpy(arquivo, argv[1]);
        idade = atoi(argv[2]);
        strcpy(nome,arquivo);
        strcat(arquivo,".txt");

        if(f = open(arquivo, O_WRONLY |O_CREAT, S_IRWXU ))
        {
            sprintf(buf,"Nome: %s\nIdade: %d\n", nome, idade);
            write(f,buf,strlen(buf));
            close(f);
        }
    }
    return 0;
}
