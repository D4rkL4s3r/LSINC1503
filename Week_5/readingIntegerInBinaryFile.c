#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
 * @pre filename != NULL, name of the file
 * @post returns the sum of all integers stored in the binary file.
 *       return -1 if the file can not be open.
 *       return -2 if the file can not be closed.
 *       return -3 if mmap() fails.
 *       return -4 if munmap() fails.
 *       return -5 if fstat() fails.
 */
int sum_file(char *filename) {
    int file, totalNumber, sum = 0;
    int* srcMap;
    if ((file = open(filename, O_RDONLY)) == -1){
        return -1;
    }
    struct stat myStruct;
    if ((fstat(file, &myStruct)) == -1){
        if (close(file) == -1){
            return -2;
        }
        return -5;
    }
    totalNumber = myStruct.st_size/sizeof(int);
    if (totalNumber == 0){
        if (close(file) == -1){
            return -2;
        }
        return 0;
    }
    if ((srcMap = (int*) mmap(NULL, totalNumber*sizeof(int), PROT_READ, MAP_SHARED, file, 0)) == MAP_FAILED){
        if (close(file) == -1){
            return -2;
        }
        return -3;
    }
    for(int i = 0; i < totalNumber; i++){
        sum += srcMap[i];
    }
    if (munmap(srcMap, totalNumber*sizeof(int)) == -1){
        if (close(file) == -1){
            return -2;
        }
        return -4;
    }
    if (close(file) == -1){
        return -2;
    };
    return sum;
}

int main(){
    return EXIT_SUCCESS;
}