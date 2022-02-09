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