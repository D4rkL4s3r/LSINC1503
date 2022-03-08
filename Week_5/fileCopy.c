#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

/*
 * @pre file_name != NULL, name of the original file
 *      new_file_name != NULL, name of the new file (the copy)
 *
 * @post copy the contents of {file_name} to {new_file_name}.
 *       return 0 if the function terminates with success, -1 in case of errors.
 */
int copy(char *file_name, char *new_file_name) {
    int close1, close2, file1, file2 = 18;
    size_t length;
    void* srcMap1;
    void* srcMap2;
    if ((file1 = open(file_name, O_RDONLY)) != -1 ){
        struct stat struct1;
        if ((fstat(file1, &struct1)) != -1){
            length = struct1.st_size;
            if(length == 0){
                file2 = open(new_file_name, O_CREAT|O_RDWR|O_TRUNC);
                return 0;
            }
            if ((srcMap1 = mmap(NULL, length, PROT_READ, MAP_SHARED, file1, 0)) != MAP_FAILED){
                if ((file2 = open(new_file_name, O_CREAT|O_RDWR|O_TRUNC)) != -1 ){
                    if ((ftruncate(file2, length)) != -1){
                        if ((srcMap2 = mmap(NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED, file2, 0)) != MAP_FAILED){
                            if ((memcpy(srcMap2, srcMap1, length)) != NULL){
                                if (munmap(srcMap2, length) != -1){
                                    if (munmap(srcMap1, length) != -1){
                                       close2 = close(file2);
                                       close1 = close(file1);
                                       if (close1 == -1 || close2 == -1){
                                           return -1;
                                       }
                                       return 0;
                                    }
                                }
                            }
                        }
                    }
                }else{
                    close2 = close(file2);
                    close1 = close(file1);
                    if (close1 == -1 || close2 == -1){
                        return -1;
                    }
                    return -1;
                }
            }
        }else{
            close1 = close(file1);
            if (close1 == -1){
                return -1;
            }
            return -1;
        }
    }
    return -1;
}

int main(){
    return EXIT_SUCCESS;
}
