#include <stdio.h>

void format_str(char *buffer, unsigned int d, char *name, char initial){
    sprintf(buffer, "Mister %s %c. has %d eggs\n", name, initial, d);
    printf("%s", buffer);
    }

int main()
{
    char buffer[50];
    int d = 42;
    char *pointeurName = "Olivier";
    char initial = 'B';
    format_str(buffer, d, pointeurName, initial);
    return 0;
}
