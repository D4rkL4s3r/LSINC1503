#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int first(void *ptr) {
    int *res = *ptr + 12;
    return res;
}
char second(void *ptr) {
    char *res = *ptr + 6;
    return *res;
}
int third(void *ptr) {
    int *res = *ptr + 45;
    return *res;
}