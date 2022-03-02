#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int eqTest(int x, int y){
    if (x == y){
        return 1;
    }else{
        return 0;
    }
}

int geTest(int x, int y){
    if(x >= y){
        return 1;
    }else{
        return 0;
    }
}

int gtTest(int x, int y){
    if(x > y){
        return 1;
    }else{
        return 0;
    }
}

int leTest(int x, int y){
    if(x <= y){
        return 1;
    }else{
        return 0;
    }
}

int ltTest(int x, int y){
    if(x < y){
        return 1;
    }else{
        return 0;
    }
}

int neTest(int x, int y){
    if(x != y){
        return 1;
    }else{
        return 0;
    }
}

int main(int argc, char *argv[]) {  
    if (argv[2][1] == 'e' && argv[2][2] == 'q'){
        return eqTest(*argv[1], *argv[3]);
    }else if (argv[2][1] == 'g' && argv[2][2] == 'e'){
        return geTest(*argv[1], *argv[3]);
    }else if (argv[2][1] == 'g' && argv[2][2] == 't'){
        return gtTest(*argv[1], *argv[3]);
    }else if (argv[2][1] == 'l' && argv[2][2] == 'e'){
        return leTest(*argv[1], *argv[3]);
    }else if (argv[2][1] == 'l' && argv[2][2] == 't'){
        return ltTest(*argv[1], *argv[3]);
    }else if (argv[2][1] == 'n' && argv[2][2] == 'e'){
        return neTest(*argv[1], *argv[3]);
    }
    EXIT_SUCCESS;
}