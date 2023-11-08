#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number;
    int length;
    long num;

    //ask user for card number
    do
    {
        length = 0;
        number = get_long("Number: ");
        num = number;

        while (num > 0)
        {
            num /= 10;
            length++;
        }
    }
    while (length < 0);

    int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16;

    //Luhn's algorithm

    //get every other number of card and multiply by 2
    card2 = number % 100 / 10 * 2;
    card4 = number % 10000 / 1000 * 2;
    card6 = number % 1000000 / 100000 * 2;
    card8 = number % 100000000 / 10000000 * 2;
    card10 = number % 10000000000 / 1000000000 * 2;
    card12 = number % 1000000000000 / 100000000000 * 2;
    card14 = number % 100000000000000 / 10000000000000 * 2;
    card16 = number % 10000000000000000 / 1000000000000000 * 2;

    //add the numbers' digits together
    card2 = card2 / 10 + card2 % 10;
    card4 = card4 / 10 + card4 % 10;
    card6 = card6 / 10 + card6 % 10;
    card8 = card8 / 10 + card8 % 10;
    card10 = card10 / 10 + card10 % 10;
    card12 = card12 / 10 + card12 % 10;
    card14 = card14 / 10 + card14 % 10;
    card16 = card16 / 10 + card16 % 10;

    //get the rest of the numbers
    card1 = number % 10;
    card3 = number % 1000 / 100;
    card5 = number % 100000 / 10000;
    card7 = number % 10000000 / 1000000;
    card9 = number % 1000000000 / 100000000;
    card11 = number % 100000000000 / 10000000000;
    card13 = number % 10000000000000 / 1000000000000;
    card15 = number % 1000000000000000 / 100000000000000;

    //sum up the numbers
    int sum = 0;
    sum = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8 + card9 + card10 + card11 + card12 + card13 + card14 + card15 + card16;

    long visa = number;
    long master = number;
    long amex = number;

    //check the first two digits by dividing the number
    while (visa >= 10)
    {
        visa /= 10;
    }

    while (master >= 100)
    {
        master /= 10;
    }

    while (amex >= 100)
    {
        amex /= 10;
    }

    //evaluate if the number meets the given card conditions and output the proper card name
    if (sum % 10 == 0 && visa == 4 && (length == 16 || length == 13)  )
    {
        printf("VISA\n");
    }
    else if (sum % 10 == 0 && length == 16 && (master >= 51 && master <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if (sum % 10 == 0 && length == 15 && (amex == 34 || amex == 37))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
