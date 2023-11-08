#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int length_argv = strlen(argv[1]);
    long key = atol(argv[1]);

    for (int i = 0; i < length_argv; i++)
    {
        char c = argv[1][i];
        if (isdigit(c) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    if (key >= 2147483622)
    {
        printf("Your number is too large\n");
        return 1;
    }

    printf("plaintext:  ");
    string plaintext = get_string("");
    printf("ciphertext: ");
    if (key > 26)
    {
        key %= 26;
    }
    for (int j = 0; j < strlen(plaintext); j++)
    {
        int keyy = key;
        if ((plaintext[j] >= 'a' && plaintext[j] <= 'z' ) || (plaintext[j] >= 'A' && plaintext[j] <= 'Z'))
        {

                if (plaintext[j] + key < 'A' || plaintext[j] + key > 'z' || (plaintext[j] + key > 'Z' && plaintext[j] + key < 'a'))
                {

                    if (plaintext[j] > 64 && plaintext[j] < 91)
                    {
                        int length_to_z = 'Z' - plaintext[j];
                        keyy -= length_to_z;
                        plaintext[j] = 64 + keyy;
                        char p = plaintext[j];
                        printf("%c", p);
                    }
                    if (plaintext[j] > 96 && plaintext[j] < 123)
                    {
                        int length_to_z = 'z' - plaintext[j];
                        keyy -= length_to_z;
                        plaintext[j] = 96 + keyy;
                        char p = plaintext[j];
                        printf("%c", p);
                    }
                }
                else
                {
                    char p = plaintext[j] + key;
                    printf("%c", p);
                }
        }
        else
        {
            char p = plaintext[j];
            printf("%c", p);
        }
    }
    printf("\n");

    return 0;
}
