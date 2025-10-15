/*
    Modified by Caleb Sandman
    Project 2 for COP3514 Program Design

    This program takes a user input and ensures it is at least 8 characters long and only contains letters and numbers
    It has been modified to ensure that at least one uppercase and one lowercase letter are used
*/

#include <stdio.h>
// check if an input is a valid password: only alphabet or digit, 8 or more characters
int main()
{
    char ch;
    int is_valid = 1;
    int count = 0;
    int upper = 0;  //keeps track of whether or not an uppercase was used
    int lower = 0;  //keeps track of whether or not a lowercase letter was used
        printf("Enter input: ");
    ch = getchar();

    while(ch != '\n')
    {
        if(!((ch >= 'a' && ch <= 'z') ||(ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')))
            is_valid = 0;
        if(ch >= 'a' && ch <= 'z')          //lower = 1 if a lowercase letter was used
            lower = 1;
        else if(ch >= 'A' && ch <= 'Z')     //upper = 1 if an uppercase letter was used
            upper = 1;
        count++;
        ch = getchar();
    }

    if(count < 8 || upper == 0 || lower == 0)   //now checks if password is > 8 characters and contains an uppercase and lower case letter
        is_valid = 0;
    if(is_valid)
        printf("Valid");
    else printf("Invalid");
    
    return 0;
}
