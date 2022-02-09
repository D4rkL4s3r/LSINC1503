#include <stdio.h>
#include <stdlib.h>

int factorial(int number){
    if(number > 1){
        return number * factorial(number-1);
    }
    else{
        return 1;
    }
}

int main(int argc, char *argv[]){
    int numberTest = factorial(9);
    printf("%d\n", numberTest);
    return EXIT_SUCCESS;
}