#include <stdio.h>
#include <stdlib.h>

void print_digit(int number){
	printf("The magic number is %d.\n", number);
}

int main(int argc, char *argv[]){
	print_digit(7);
	return EXIT_SUCCESS;
}
