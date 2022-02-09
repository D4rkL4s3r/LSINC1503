#include <stdio.h>

int strcasecmp(const char *s1, const char *s2) {
    int i = 0;
while(s1[i] != '\0' && s2[i] != '\0'){
            if((s1[i] == s2[i]) || ((s1[i] + 32) == s2[i]) || ((s1[i] - 32) == s2[i])){
                i++;
            }else{
                return s1[i] - s2[i];
            }
    }
return s1[i] - s2[i];
}

int main(){
    int answer1 = strcasecmp("azerty", "Azerty");
    int answer2 = strcasecmp("Azerty", "azert");
    int answer3 = strcasecmp("azErt", "azerty");
    printf("%d + %d + %d\n", answer1, answer2, answer3);
}