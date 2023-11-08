#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input;
    do
    {
        input = get_int("Height: ");
    }
    while (input <= 0 || input > 8);

    int bricks_in_row = 1;
    int spaces = input;
    for (int height = 0; height < input; height++)
    {
        for (int j = 0; j < spaces -1; j++)
        {
            printf(" ");
        }
        for (int row = 0; row < bricks_in_row; row++)
        {
            printf("#");
        }
        printf("\n");

        spaces--;
        bricks_in_row++;
    }
}
