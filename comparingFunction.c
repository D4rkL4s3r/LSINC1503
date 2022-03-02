#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp_func(uint8_t f1(uint8_t), uint8_t f2(uint8_t)){
    for(uint8_t i = 0; i < 255; i++){
        if(f1(i) != f2(i)){
            return 0;
        }
    }
    return 1;
}

int main(){
    return 0;
}