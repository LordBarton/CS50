#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// The alphabet
int LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
        return 0;
    }
    if (score2 > score1)
    {
        printf("Player 2 wins!\n");
        return 0;
    }
    printf("Tie!\n");

    return 0;
}

int compute_score(string word)
{
    // Compute and return score for the word
    int score = 0;
    int length = strlen(word);

    // Change each letter in word to uppercase
    for (int j = 0; j < length; j++)
    {
        word[j] = (char)toupper((unsigned char)word[j]);
    }

    // Iterate through the alphabet
    for (int i = 0; i < 25; i++)
    {
        // Iterate through the word's letters
        for (int j = 0; j < length; j++)
        {
            // If the current letter is the same as the current one in the alphabet, increase score by the corresponding point
            if (word[j] == LETTERS[i])
            {
                score += POINTS[i];
            }
        }
    }

    // Return the total calculated score
    return score;
}
