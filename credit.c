#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include<math.h>

int main(void)
{
    long card;
    card = get_long("Enter Card Number: ");
    long cardN = card;
    
    int lastPlus = 0; // Sum of last digit group.
    int secLastPlus = 0; // Sum of double of second last digit group.
    do
    {
        int lastD = card % 10; // Get last digit.
        lastPlus = lastPlus + lastD; 
        card = (card - lastD) / 10;
        int secLastD = card % 10; // Get second last digit.
        int secLastDx2 = secLastD * 2; // Get second last digit's double.
        if (secLastDx2 > 9)
        {
            int LD = secLastDx2 % 10; // Get last digit.
            int FD = (secLastDx2 - LD) / 10; // Get first digit.
            secLastDx2 = FD + LD;
        }
        secLastPlus = secLastPlus + secLastDx2;
        card = (card - secLastD) / 10;
    }
    while (card != 0);
    if ((lastPlus + secLastPlus) % 10 == 0)
    {
        int result = (lastPlus + secLastPlus);
        //printf("The last digit in that sum is 0 because the result is %i\n", result);
        for (int i = 13; i < 17; i++)
        {
            // When divide card / p you will get the first numbers
            long firstNumbers = cardN / pow(10, i); 
            if (firstNumbers == 4)
            {
                printf("VISA\n");
                return 0;
            }
            else if (firstNumbers == 34 || firstNumbers == 37)
            {
                printf("AMEX\n");
                return 0;
            }
            else if (firstNumbers == 51 || firstNumbers == 52 || firstNumbers == 53 ||                 firstNumbers == 54 || firstNumbers == 55)
            {
                printf("MASTERCARD\n");
                return 0;
            }
        }
        printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
