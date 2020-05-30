#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int key;
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]))
            {
                key = atoi(argv[1]);
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        // printf("Success\n");
        // printf("%i\n", key);

        string plaintext = get_string("plaintext:  ");

        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (isalpha(plaintext[i]) && isupper(plaintext[i]))
            {
                plaintext[i] = (plaintext[i] + key - 65) % 26 + 65;
            }
            else if (isalpha(plaintext[i]) && islower(plaintext[i]))
            {
                plaintext[i] = (plaintext[i] + key - 97) % 26 + 97;
            }
        }

        printf("ciphertext: %s", plaintext);
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
