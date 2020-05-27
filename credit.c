#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card_number;

    do
    {
        card_number = get_long("Enter card number: ");
        // printf("Card number: %li \n", card_number);
    }
    while (card_number < 1);

    long card_number0 = card_number;
    long card_number1 = card_number;
    long card_number2 = card_number;
    long card_number3 = card_number;
    long card_number4 = card_number;

    int length;
    int first_digit;
    int two_digits;
    int last_digit1;
    int last_digit2;
    int double_digit;
    int sum1 = 0;
    int sum2 = 0;
    int sum = 0;

    for (length = 0; card_number0 != 0; length++)
    {
        card_number0 /= 10;
    }

    // printf("Length: %i \n", length);

    while (card_number1 >= 10)
    {
        first_digit = card_number1 /= 10;
    }

    // printf("first digit: %i", first_digit);

    while (card_number2 >= 100)
    {
        two_digits = card_number2 /= 10;
    }

    // printf("first two digits: %i", two_digits);

    while (card_number3 > 0)
    {
        last_digit1 = card_number3 % 10;
        sum1 = sum1 + last_digit1;
        card_number3 /= 100;
    }

    // printf("sum1 is: %i  \n", sum1);

    card_number4 /= 10;

    while (card_number4 > 0)
    {
        last_digit2 = card_number4 % 10;
        if (last_digit2 * 2 >= 10)
        {
            double_digit = last_digit2 * 2 - 9;
        }
        else
        {
            double_digit = last_digit2 * 2;
        }
        card_number4 /= 100;
        sum2 = sum2 + double_digit;
    }

    // printf("sum2 is: %i  \n", sum2);

    sum = sum1 + sum2;
    // printf("sum is: %i  \n", sum1 + sum2);

    if (length == 15 && (two_digits == 34 || two_digits == 37) && sum % 10 == 0)
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (two_digits >= 51 && two_digits <= 55) && sum % 10 == 0)
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && (first_digit == 4) && sum % 10 == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
