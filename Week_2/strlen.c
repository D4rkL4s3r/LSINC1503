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
 
  //Appel de la fonction et stockage du résultat
  size_t resultat = strlen("lkhjuyguyg");
  //Affichage
  printf("%ld\n", resultat);
  return 0;
}