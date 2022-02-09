#include <stdio.h>
#include <stdlib.h>

int factorial(int number){
    int result = 1;
    while (number > 0)
    {
        result *= number;
        number--;
    }
    return result;
}

int main(int argc, char *argv[]){
    int numberTest = factorial(9);
    printf("%d\n", numberTest);
    return EXIT_SUCCESS;
}