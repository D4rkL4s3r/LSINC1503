#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

/*
 * @pre filename != NULL, index >= 0
 * @post return the integer at the index {index}
 *       of the array in the file {filename}.
 *       return -1 in case of error.
 *       return -2 if index >= length of array.
 */
int get(char *filename, int index) {
    int file, length, numberFound;
    int* srcMap;
    if ((file = open(filename, O_RDONLY)) == -1){
        return -1;
    }
    struct stat myStruct;
    if ((fstat(file, &myStruct)) == -1){
        if (close(file) == -1){
            return -1;
        }
        return -1;
    }
    length = myStruct.st_size/sizeof(int);
    if (length <= index){
        if (close(file) == -1){
            return -1;
        }
        return -2;
    }
    if ((srcMap = (int*) mmap(NULL, length*sizeof(int), PROT_READ, MAP_SHARED,         file, 0)) == MAP_FAILED){
        if (close(file) == -1){
            return -1;
        }
        return -1;
    }
    numberFound = srcMap[index];
    if (munmap(srcMap, length*sizeof(int)) == -1){
        if (close(file) == -1){
            return -1;
        }
        return -1;
    }
    if (close(file) == -1){
        return -1;
    };
    return numberFound;
}

/*
 * @pre filename != NULL, index >= 0
 * @post set the element in the file {filename}
 *       at index {index} at value {value}.
 *       do nothing in case of errors
 */
void set(char *filename, int index, int value) {
    int file, length;
    int* srcMap;
    if ((file = open(filename, O_RDONLY)) != -1){
        struct stat myStruct;
        if ((fstat(file, &myStruct)) != -1){
            length = myStruct.st_size/sizeof(int);
            if (length > index){
                if ((srcMap = (int*) mmap(NULL, length*sizeof(int), PROT_READ, MAP_SHARED, file, 0)) != MAP_FAILED){
                    srcMap[index] = value;
                    if (munmap(srcMap, length*sizeof(int)) != -1){
                        close(file);
                    }else{
                        close(file);
                    }
                }else{
                    close(file);
                }
            }else{
                close(file);
            }
        }else{
            close(file);
        }
    }
}

int main(){
    return EXIT_SUCCESS;
}
