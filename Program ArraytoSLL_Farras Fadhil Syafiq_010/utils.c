#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void inputString(char **s) {
    char *temp = malloc(1);
    char c; 
	int i = 0;
    while(1) {
        c = getchar();
        
        if (c == '\n') break;
        
        temp = realloc(temp, i + 1);
        temp[i] = c;
        
        if (temp == NULL) {
            printf( "Memory allocation failed\n");
            break;
        }

        i++;
    }
    temp[i] = '\0';
    *s = temp;
}