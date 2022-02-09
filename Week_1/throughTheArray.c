#include <stdio.h>
#include <stdlib.h>

int tab_find(int tab[], int len, int elem){
    for (int i = 0; i < len; i++){
        if (elem == tab[i]){
            return i;
        } 
    }  
    return -1;
}

int main(int argc, char *argv[]){
    int tab[9] = {2, -2, 3, -1, 5, 6, 4, -8, 9};
    int tab2[0] = {};
    int numberTest0 = tab_find(tab, 9, 5);
    printf("%d\n", numberTest0);
    int numberTest1 = tab_find(tab, 9, 2);
    printf("%d\n", numberTest1);
    int numberTest2 = tab_find(tab, 9, 9);
    printf("%d\n", numberTest2);
    int numberTest3 = tab_find(tab, 9, 10);
    printf("%d\n", numberTest3);
    int numberTest4 = tab_find(tab2, 0, 5);
    printf("%d\n", numberTest4);
    return EXIT_SUCCESS;
}