#include <cs50.h>
#include <stdio.h>

int checksumFalse(long number);

int main(void)
{
    long number = get_long("Number:\n");
    string type = "INVALID";
    // First check it with checksum
    if (checksumFalse(number))
    {
        printf("%s\n", type);
        return 0;
    }
    //Second check number of digits to specifiy which type of card it is
    if ((number >= 4E12 && number < 5E12) || (number >= 4E15 && number < 5E15))
    {
        // Visa uses 13- and 16-digit numbers
        //all Visa numbers start with 4
        type = "VISA";

    }
    else if ((number >= 34E13 && number < 35E13) || (number >= 37E13 && number < 38E13))
    {
        // American Express uses 15-digit numbers
        //All American Express numbers start with 34 or 37;
        type = "AMEX";
    }
    else if (number >= 51E14 && number < 56E14)
    {
        // MasterCard uses 16-digit numbers
        //MasterCard numbers start with 51, 52, 53, 54, or 55
        type = "MASTERCARD";
    }


    printf("%s\n", type);
    return 0;
}

int checksumFalse(long number)
{
    int sum = 0;
    int i = 0;
    int digit = 0;
    while (number > 0)
    {
        digit = number % 10;
        if (i % 2 == 1)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = digit % 10 + digit / 10;
            }
        }
        sum += digit;
        //printf("sum: %i", sum);
        number /= 10;
        //printf("number: %ld", number);
        i++;
    }
    if (sum % 10 == 0)
    {
        return 0;
    }
    return 1;
}