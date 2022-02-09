#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pal(char *str){
    if (str == NULL){
        return -1;
    }
    else {
        int begin = 0;
        int end = strlen(str) - 1;
        while(begin < end){
            while (str[begin] == ' '){
                begin ++;
            }
            while (str[end] == ' '){
                end--;
            }
            if (str[begin] == str[end]){
                begin ++;
                end--;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
}


int main(){
    printf("%d\n", pal("azertytreza"));
    printf("%d\n", pal(""));
    printf("%d\n", pal("azertyytreza"));
    printf("%d\n", pal("azetytreza"));
    return 0;
}