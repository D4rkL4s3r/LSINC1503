/*
* Creates a buffer that has the same size as src, and copies the content of src to this buffer.
*
* @src: string to be copied
* @return: return pointer. if src == NULL or in case of error, return NULL
*
* Remember that strings are terminated with '\0' and that strlen("abc") returns 3 even if 4 bytes are required to store this string.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *buf_strcpy(const char *src) {
    // le plus 1 est la pour la lngueur du string avec le \0.
    int longueur = strlen(src) + 1;
    // malloc alloue un espèce mémoire
    char* buffer = malloc(longueur);
    if(src == NULL){
        return NULL;
    } else{
        for (int i = 0; i <= longueur; i++){
            if (i == longueur){
                buffer[i] = '\0';   
            } else{
                buffer[i] = src[i];
            }
        }         
    }
}
int main(){
    return 0;
}