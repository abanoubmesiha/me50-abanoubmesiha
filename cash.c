#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("change owed: ");
    }
    while (change <= 0);
    int cent = round(change * 100);
    int result = 0;
    
    while (cent >= 25) // can i take a quarter?
    {
        result++;
        cent = cent - 25; 
    }
    while (cent >= 10)  // can i take a dime?
    {
        result++;
        cent = cent - 10;
    }
    while (cent >= 5) // can i take a nickel?
    {
        result++;
        cent = cent - 5;
    }
    while (cent >= 1)// can i take a penny?
    {
        result++;
        cent = cent - 1;
    }

    printf("%i\n", result);
}
