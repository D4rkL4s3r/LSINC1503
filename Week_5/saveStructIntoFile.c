#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

typedef struct point {
    int x;
    int y;
    int z;
} point_t;

/*
 * @pre pt != NULL, pointer to the first point_t in the array
 *      size > 0, the length of the array.
 *      filename != NULL
 * @post writes the array of point_t in the file.
 *       return 0 is everything worked correctly
 *       -1 if open() failed.
 *       -2 if close() failed.
 *       -3 if mmap() failed.
 *       -4 if munmap() failed.
 *       -5 if msync() failed.
 *       -6 if ftruncate() failed.
 *
 */
int save(point_t *pt, int size, char *filename){
    void* mapNumber;
    int closeNumber;
    int openNumber = open(filename, O_CREAT|O_RDWR|O_TRUNC, S_IRUSR|S_IWUSR);
    if (openNumber == -1){
        /*closeNumber = close(openNumber);
        if (closeNumber == -1){
            close(openNumber);
            return -2;
        }*/
        return -1;
    }
    int ftNumber = ftruncate(openNumber, sizeof(point_t)*size);
    if (ftNumber == -1){
        closeNumber = close(openNumber);
        if (closeNumber == -1){
            close(openNumber);
            return -2;
        }
        return -6;
    }
    mapNumber = mmap(NULL, size*sizeof(point_t), PROT_READ|PROT_WRITE, MAP_SHARED, openNumber, 0);
    if (mapNumber == MAP_FAILED){
        closeNumber = close(openNumber);
        if (closeNumber == -1){
            close(openNumber);
            return -2;
        }
        return -3;
    }
    memcpy(mapNumber, pt, size*sizeof(point_t));
    int syncFile = msync(mapNumber, size*sizeof(point_t), MS_SYNC);
    if (syncFile == -1){
        closeNumber = close(openNumber);
        if (closeNumber == -1){
            close(openNumber);
            return -2;
        }
        return -5;
    }
    int munmapNumber = munmap(mapNumber, size*sizeof(point_t));
    if (munmapNumber == -1){
        closeNumber = close(openNumber);
        if (closeNumber == -1){
            close(openNumber);
            return -2;
        }
        return -4;
    }

    closeNumber = close(openNumber);
    if (closeNumber == -1){
        close(openNumber);
        return -2;
    }
    return 0;
}