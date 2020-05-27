#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int number;

    do {
        number = get_int("Enter pyramid height: ");
    }

    while (number < 1 || number > 8);

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

        printf("  ");

        for (j = 1; j <= i; j++) {
            printf("#");
        }

        printf("\n");

    }
}
