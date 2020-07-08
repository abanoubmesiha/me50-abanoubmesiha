#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argv[2] != NULL || argv[1] == NULL)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string key = argv[1];
    // if not one integer
    // throw error and return 1
    for (int i = 0; i < strlen(key); i++)
    {
        char c = key[i];
        if (!(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Get the key.
    int checkedKey = atoi(key);
    string plaintext = get_string("plaintext: ");
    printf("key: %i\n", checkedKey);
    printf("plaintext: %s\n", plaintext);
    printf("ciphertext: ");

    // Make it number and get cipher text.
    for (int i = 0; i < strlen(plaintext); i++)
    {
        int ASCII = plaintext[i];
        if (ASCII >= 97 && ASCII <= 122)
        {
            // Small letters
            int c = ((ASCII - 96) + checkedKey) % 26;
            // ciphertext[i] = c + 96;
            printf("%c", c + 96);
        }
        else if (ASCII >= 64 && ASCII <= 90)
        {
            // Capital letters
            int c = ((ASCII - 63) + checkedKey) % 26;
            printf("%c", c + 63);
        }
        else
        {
            // Print anything else as it is.
            printf("%c", ASCII);
        }
    }
    printf("\n");
}