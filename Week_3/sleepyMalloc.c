#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

/* Wrapper to the malloc system call.
 * If malloc fails, sleep for 5 seconds, and then try again.
 * If malloc failed 10 times in a row, return NULL.
 */
void *sleepy_malloc(size_t s) {
    int failTime = 0;
    while (failTime <= 10){
        malloc(5);
        if (errno!=0){
            sleep(5);
        } else{
            return malloc(s);
        }
    }
    return NULL;
}

int main(){
    return 0;
}