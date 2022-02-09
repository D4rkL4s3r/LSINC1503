#include <stdio.h>

char* strcat(char* dest, const char* src){
    int lengthDest = sizeof(dest);
    int lengthsrc = sizeof(src);
    for (int i = 0; i < lengthsrc; i++){
        dest[lengthDest + i] = src[i];
        printf("%d",i);
    }
    return dest;
}

int main(){
    char* c = "azerty";
    char* v = "azerty";
    printf("%s\n", strcat(c, v));
}
