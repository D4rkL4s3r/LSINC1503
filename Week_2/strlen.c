#include <string.h>
#include <stdio.h>
 
size_t strlen(const char* s) {
	int i;
	i=0;
	while(s[i]!='\0')
		++i;
	return i;
}
 
int main() {
  size_t resultat = strlen("lkhjuyguyg");
  printf("%ld\n", resultat);
  return 0;
}
