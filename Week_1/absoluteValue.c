#include <stdio.h>
#include <stdlib.h>

int absoluteValue(int number){
    if (number < 0){
        number = -number;
    }
    return number;
}

int main(int argc, char *argv[]){
    int numberTest = absoluteValue(-9);
    printf("%d\n", numberTest);
    return EXIT_SUCCESS;
}
