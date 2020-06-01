#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool check_length(char key[]);
bool check_alpha(char key[]);
bool check_duplicate(char key[]);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (argc == 2 && !(check_length(argv[1])))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (argc == 2 && !(check_alpha(argv[1])))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    else if (argc == 2 && check_duplicate(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    else
    {
        // printf("Success");
        string plaintext = get_string("plaintext:  ");
        string key = argv[1];

        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (isupper(plaintext[i]))
            {
                plaintext[i] = toupper(key[plaintext[i] - 65]);
            }
            else if (islower(plaintext[i]))
            {
                plaintext[i] = tolower(key[plaintext[i] - 97]);
            }
        }

        printf("ciphertext: %s", plaintext);
        printf("\n");
        return 0;
    }
}

bool check_length(char key[])
{
    int count = 0;
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        count++;
    }
    if (count == 26)
    {
        printf("There are %i letters\n", count);
        return true;
    }
    else
    {
        printf("There are %i letters\n", count);
        return false;
    }
}

bool check_alpha(char key[])
{
    int alpha = 0;
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isalpha(key[i]))
        {
            alpha++;
            if (alpha == 26)
            {
                return true;
            }
        }
    }
    return false;
}

bool check_duplicate(char key[])
{
    int repeated = 0;
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (key[i] == key[j])
            {
                printf("There are duplicates...\n");
                return 1;
            }
        }
    }
    return false;
}
