#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int digit_checker(string text);
char rotate(int key, char letter);
int main(int argc, string argv[])
{
    // check if the command line arguments are valid
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (!digit_checker(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // get the key and plaintext
    int key = atoi(argv[1]);
    string plain = get_string("plaintext:  ");
    printf("ciphertext: ");
    // for-loop to rotate every character in plaintext, and print results
    // define helper function to rotate single character instead of rotate the whole string
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        printf("%c", rotate(key, plain[i]));
    }
    printf("\n");
}
int digit_checker(string text)
{
    // check if any character in the string is a digit
    // return 1 if every character in the string is a digit, else return 0
    int flag = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (!isdigit(text[i]))
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
char rotate(int key, char letter)
{
    //rotate character according to the rule.
    if (isalpha(letter))
    {
        int p = isupper(letter) ? (int)letter - 65 : (int)letter - 97;
        int c = (p + key) % 26;
        c = isupper(letter) ? c + 65 : c + 97;
        return (char)c;
    }
    return letter;
}
