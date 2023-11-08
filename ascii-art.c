#include <stdio.h>

int main(void)
{
    int n;
    int length;
    int spaces;
    int spaces2;
    int length2;
    int spaces3;
    int spaces4;

    do
    {
    printf("Enter length: ");
    scanf("%d", &n);
    }
    while(n <= 0);

    printf("_____\n     | ");
    for(spaces = 0;spaces < n; spaces++)
    {
        printf("          ");
    }

    printf("__________\n      |         ");
    for(spaces2 = 1; spaces2 < n; spaces2++)
    {
        printf("          ");
    }
    printf("|          |\n_____|");

    for(length = 0; length < n; length++)
    {
        printf("__________");
    }
    printf("|           |\n");

    int girth = 0;
    while(girth < 2)
    {
        printf("       ");
        for(spaces = 0; spaces < n; spaces++)
        {
            printf("          ");
        }
        printf("            |\n");
        girth ++;
    }

    printf("_____ ");
    for(length2 = 0; length2 < n; length2++)
    {
        printf("__________");
    }
    printf("             |\n");
    printf("     |");

    for(spaces3 = 0; spaces3 < n; spaces3++)
    {
        printf("          ");
    }
    printf("|           |\n");
    printf("      |         ");

    for(spaces4 = 1; spaces4 < n; spaces4++)
    {
        printf("          ");
    }
    printf("|__________|\n");
    printf("_____|\n\n");
    return 0;
}
