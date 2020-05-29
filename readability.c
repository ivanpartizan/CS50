#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    // printf("%s \n", text);

    float count_letters = 0;
    float count_words = 0;
    float count_sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            count_letters++;
        }
        if (text[i] == 32)
        {
            count_words++;
        }
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            count_sentences++;
        }
    }

    // printf("There are %f letters here... \n", count_letters);
    // printf("There are %f words here... \n", count_words + 1);
    // printf("There are %f sentences here... \n", count_sentences);

    float l = count_letters * 100 / (count_words + 1);
    float s = count_sentences * 100 / (count_words + 1);

    float index = 0.0588 * l - 0.296 * s - 15.8;

    // printf("%f %f %f \n", l, s, round(index));

    if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round(index) >= 2 && round(index) < 16)
    {
        printf("Grade %.0f\n", round(index));
    }
    else
    {
        printf("Grade 16+\n");
    }
}
