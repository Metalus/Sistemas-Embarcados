#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char string[] = "Ola mundo!";
    int fp = open("ola_mundo.txt", O_WRONLY |O_CREAT);
    int i;

    for(i=0; string[i]; i++)
        write(fp, &(string[i]), 1); // Grava a string, caractere a caractere

    close(fp);
    return 0;
}
