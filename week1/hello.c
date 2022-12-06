#include<stdio.h>
#include<cs50.h>
int main(void)
{
    // Enter a username
    string name = get_string("What's your name? ");
    // say hello to this user
    printf("hello, %s\n", name);
}