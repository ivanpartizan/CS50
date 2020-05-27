#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int number = get_int("Enter pyramid height: ");

    while (number < 1 || number > 8) {
        number = get_int("Enter a number between 1 and 8: ");
        if (number > 0 && number < 9) {
            break;
        }
    }

    int i;
    int j;
    int space;

    for (i = 1; i <= number; i++) {
        for (space = number - i; space > 0; space--) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }
}
