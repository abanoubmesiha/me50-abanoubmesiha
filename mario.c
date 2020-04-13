#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number;
    do
    {
        number = get_int("Positive Number: ");
    }
    while (number < 1 || number > 8);
    for (int line = 0; line < number; line++)
    { 
        for (int space = number - line - 1; space > 0; space--)
        {
            printf(" ");
        }
        for (int width = 0; width <= line; width++)
        {
            printf("#");
        }
        printf("\n");
    }
}
