#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    // display message if user puts in too many arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // check for length of command line argument
    int length = strlen(argv[1]);

    // or if the argument isn't as long as the alphabet
    if (length != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    // or if it isn't entirely alphabetical
    for (int i = 0; i < length; i++)
    {
        char c = argv[1][i];
        if (isalpha(c) == 0)
        {
            printf("Key contains non-alphabetical characters\n");
            return 1;
        }
    }

    // or if it contains more than one of the same letter
    for (int j = 0; j < length; j++)
    {
        string copy = argv[1];
        int total = 0;
        for (int h = 0; h < length; h++)
        {
            if (copy[j] == argv[1][h] || copy[j] == tolower(argv[1][h]))
            {
                total += 1;
            }
            if (total > 1)
            {
                printf("Key can't contain more than one of each letter\n");
                return 1;
            }
        }
    }

    // ask user to input the text they want to be encrypted and print it on the same line
    printf("plaintext:  ");
    char plaintext[100];
    printf("");
    fgets(plaintext, 100, stdin);

    // store the alphabet in string for reference
    string alphabet = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    printf("ciphertext: ");

    int f = 0;
    int g = 0;
    int length2 = strlen(plaintext);

    // iterate through the plaintext
    while (f != length2)
    {
        // if the character is a letter
        if (isalpha(plaintext[f]) != 0)
        {
            // iterate through the plaintext and alphabet, whilst comparing them
            if (plaintext[f] == alphabet[g] || plaintext[f] == tolower(alphabet[g]))
            {
                // if the character is lowercase, print it as such
                if (isupper(plaintext[f]) == 0)
                {
                    printf("%c", tolower(argv[1][g]));
                    f += 1;
                    g = 0;
                }
                // the same goes for uppercase
                else
                {
                    printf("%c", toupper(argv[1][g]));
                    f += 1;
                    g = 0;
                }
            }
            // if the current alphabetical character doesn't equal the one in plaintext, skip to the next one
            else
            {
                g++;
            }
        }
        // if the character isn't a letter, print it unchanged
        else
        {
            printf("%c", plaintext[f]);
            f += 1;
        }
    }
    return 0;
}
