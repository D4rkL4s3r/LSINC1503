#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
 * @pre filename != NULL
 * @post return 0 if the file {filename} exist. -1 Otherwise.
 */
 int file_exists(char *filename){
    int file;
    file = open(filename, O_RDONLY);
    if (file == -1){
        return -1;
    }
    close(file);
    return 0;
 }

int main(){
    return EXIT_SUCCESS;
}