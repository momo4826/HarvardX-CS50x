#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int alpha_checker(string text);
int repeat_checker(string text);

// test case "This is CS50" as "Cbah ah KH50" using YUKFRNLBAVMWZTEOGXHCIPJSQD
// YyKFRNLBAVMmZTEOGXHCIPJSQq
int main(int argc, string argv[])
{
    // check if the command line arguments are valid
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1]; //get key
    if (strlen(key) != 26 || !alpha_checker(key))
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    // check if there are repeated characters in key (this restriction isn't indicted in problem description)
    if (repeat_checker(key))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    // get plaintext
    string plain = get_string("plaintext:  ");
    // get ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (!isalpha(plain[i]))
        {
            printf("%c", plain[i]);
        }
        else
        {
            int idx = isupper(plain[i]) ? (int)plain[i] - 65 : (int)plain[i] - 97;
            char res = isupper(plain[i]) ? toupper(key[idx]) : tolower(key[idx]);
            printf("%c", res);
        }
    }
    printf("\n");
    return 0;
}
int alpha_checker(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (!isalpha(text[i]))
        {
            return 0;
        }
    }
    return 1;
}
int repeat_checker(string text)
{
    // no repeat return 0, else return 1
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int tmp1 = (int)toupper(text[i]);
            int tmp2 = (int)toupper(text[j]);
            if (tmp1 == tmp2)
            {
                return 1;
            }
        }
    }
    return 0;
}
