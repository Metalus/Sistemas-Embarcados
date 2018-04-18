#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int i;
    if(argc < 2)
        return 0;
    for(i = 1;i < argc;i++)
        system(argv[i]);

    return 0;
}

