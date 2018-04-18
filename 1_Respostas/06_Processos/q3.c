
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if(argc < 2)
        return 0;

        if(fork() == 0)
           execvp(argv[0], argv);

    return 0;
}

