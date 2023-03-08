#include <stdio.h>


int main (int argc, char *argv[]){

    for (int i = 0; i < argc; ++i)
    {
        printf("The argument you printed is ");
        printf(argv[i]);
        printf("\n");
    }
    
}