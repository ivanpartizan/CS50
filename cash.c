#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    // Initialize values

    float dollars;
    int cents;

    // Prompt user for input

    do {
        dollars = get_float("How much is your change? ");
        cents = round(dollars * 100);
    }
    while (dollars <= 0);

    // printf("I have %.2f dollars, which is %i cents...\n", dollars, cents);

    // Set values for coins

    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    int coins = 0;

    // Check change and add coins

    while (cents > 0) {
        if (cents >= 25) {
            cents = cents - quarter;
            coins++;
        }
        else if (cents >= 10) {
            cents = cents - dime;
            coins++;
        }
        else if (cents >= 5) {
            cents = cents - nickel;
            coins++;
        }
        else {
            cents = cents - penny;
            coins++;
        }
    }
    printf("Coins: %i\n", coins);
}
