#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *calloc2(size_t nmemb, size_t size) {
    void *res;
    res = malloc(nmemb * size);
    return res;
}