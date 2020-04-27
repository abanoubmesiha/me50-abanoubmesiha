#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("text: ");
    int lettersN = 0;
    int wordsN = 0;
    int sentsN = 0;

    for (int i = 0, n = strlen(text);i < n ; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            lettersN++; // Calculate letters.
        }
        else if (text[i] == ' ' && i > 0 && text[i-1] != ' ')
        {
            wordsN++; // Calculate words by calculating spaces.
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentsN++; // Calculate sentences.
        }
    }
    if (text[strlen(text)-1] != ' ')
    {
        wordsN++; // If last letter isn't a space, add the last word to the sum.
    }
        //printf("%i letter(s)\n", lettersN);
        //printf("%i word(s)\n", wordsN);
        //printf("%i sentence(s)\n", sentsN);
        int index = round(0.0588 * lettersN /wordsN  * 100 -  0.296 * sentsN /wordsN  * 100 - 15.8);
        if (index >= 16)
        {
            printf("Grade 16+\n");
        }
        else if (index < 1)
        {
            printf("Before Grade 1\n");
        }
        else
        {
        printf("Grade %i\n", index);
        }
}