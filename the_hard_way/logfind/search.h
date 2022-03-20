#include <limits.h>
#include <string.h>
#include <stdio.h>
 
#define NO_OF_CHARS 256
#define RED(string) "\x1b[31m" string "\x1b[0m"
#define BLUE(string) "\x1b[34m" string "\x1b[0m"

int max (int a, int b) { return (a > b)? a: b; }
 
void badCharHeuristic( char *str, int size,
                        int badchar[NO_OF_CHARS])
{
    int i;
 
    for (i = 0; i < NO_OF_CHARS; i++)
         badchar[i] = -1;
 
    for (i = 0; i < size; i++)
         badchar[(int) str[i]] = i;
}
 
void search( char *txt,  char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int back = m; 
    int badchar[NO_OF_CHARS];
 
    badCharHeuristic(pat, m, badchar);
 
    int s = 0; 
               
    while(s <= (n - m))
    {
        int j = m-1;
 
        while(j >= 0 && pat[j] == txt[s+j])
            j--;
 
        if (j < 0)
        {
            printf("\npattern occurs at shift = " BLUE("%d") "\n\n", s);
 	    
	    for (int i = 0; i < ((int)s);i++) {
	    	printf("%c",txt[i]);
	    }
	    
 	    for (int i = (int)s; i < ((int)s + back);i++) {
	    	printf(RED("%c"),txt[i]);
	    }

 	    for (int i = ((int)s + back); i < n;i++) {
	    	printf("%c",txt[i]);
	    }
	    printf("\n");
	    s += max(1, j - badchar[txt[s+j]]);
        }
 
        else
            s += max(1, j - badchar[txt[s+j]]);
    }
}
 


