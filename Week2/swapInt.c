#include <stdio.h>

void swap(int *i, int *j){
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

int main(){
    int i = 17;
    int j = 23;
    swap(&i, &j);
    printf("%d %d", i, j);
}
