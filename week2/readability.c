#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int letter_counter(string text);
int word_counter(string text);
int sen_counter(string text);
int main(void)
{
    string text = get_string("Text: ");
    int letters = letter_counter(text), words = word_counter(text), sentences = sen_counter(text);
    //it's a bit difficult to just restrict two digits after decimal point
    float L = round((float)letters / (float)words * 100 * 100) / 100.0;
    float S = round((float)sentences / (float)words * 100 * 100) / 100.0;
    float tmp = 0.0588 * L - 0.296 * S - 15.8;
    // round float to nearest integer, acutally you can use round here
    int grade = ((int)(tmp + 0.5) > (int) tmp) ? (int)(tmp + 0.5) : (int)tmp;
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

}

int letter_counter(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        text[i] = toupper(text[i]);
        // should use '' for single character not ""!!!
        //  a letter is any lowercase character from a to z or any uppercase character from A to Z
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            count++;
        }
    }
    return count;
}

int word_counter(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // should use '' for single character not ""!!!
        //any sequence of characters separated by spaces should count as a word,
        if (text[i] == ' ')
        {
            count += 1;
        }
    }
    count++;
    return count;
}
int sen_counter(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // should use '' for single character not ""!!!
        //any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            count += 1;
        }
    }
    return count;
}