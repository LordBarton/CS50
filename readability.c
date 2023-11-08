#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double count_letters(string input);
double count_words(string input);
double count_sentences(string input);


int main(void)
{
    // Ask user for input.
    string text = get_string("Text: ");

    // Calculate the Coleman-Liau index according to the formula.
    double L = count_letters(text) / count_words(text) * 100;
    double S = count_sentences(text) / count_words(text) * 100;

    double index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the proper grade as per the index result.
    if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else
    {
        int result = round(index);
        printf("Grade %d\n", result);
        return 0;
    }
}

double count_letters(string input)
{
    int length = strlen(input);
    double letters = 0;

    // Iterate through the input.
    for (int i = 0; i < length; i++)
    {
        // If the current character is a letter, increase letter count by one.
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            letters ++;
        }
    }
    return letters;
}

double count_words(string input)
{
    int length = strlen(input);
    double words = 0;

    // Iterate through the input.
    for (int i = 0; i < length; i++)
    {
        // When the current character is a white space, increase word count by one.
        if (input[i] == ' ')
        {
            words ++;
        }
    }
    // Because there is no space after the last word in the sentence, add one to the word count.
    words += 1;
    return words;
}

double count_sentences(string input)
{
    int length = strlen(input);
    double sentences = 0;

    // Iterate through the input.
    for (int i = 0; i < length; i++)
    {
        // If the current character hits one of these symbols, increase sentence count by one.
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentences ++;
        }
    }
    return sentences;
}
