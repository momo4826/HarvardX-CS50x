#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // get positive cents
    int cents;
    do
    {
        cents = get_int("Change owed:");
    }
    while (cents < 0);

    return cents;
}

int calculate_quarters(int cents)
{
    // init number to be returned
    int num = 0;
    //calculate the number
    while (cents >= 25)
    {
        num += 1;
        cents -= 25;
    }
    //return the number
    return num;
}

int calculate_dimes(int cents)
{
    // init number to be returned
    int num = 0;
    //calculate the number
    while (cents >= 10)
    {
        num += 1;
        cents -= 10;
    }
    //return the number
    return num;
}

int calculate_nickels(int cents)
{
    // init number to be returned
    int num = 0;
    //calculate the number
    while (cents >= 5)
    {
        num += 1;
        cents -= 5;
    }
    //return the number
    return num;
}

int calculate_pennies(int cents)
{
    // init number to be returned
    int num = 0;
    //calculate the number
    while (cents >= 1)
    {
        num += 1;
        cents -= 1;
    }
    //return the number
    return num;
}
