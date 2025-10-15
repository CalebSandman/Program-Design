/*
    Modified by Caleb Sandman
    Project 5 for COP3514 Program Design

    This program takes a user input and ensures it is at least 8 characters long and only contains letters and numbers
    It has been modified to ensure that at least one uppercase and one lowercase letter are used

    Program has been modified to use command line arguments as inputs
*/

#include <stdio.h>
#include <string.h>

// check if an input is a valid password: only alphabet or digit, 8 or more characters
int main(int argc, char *argv[])
{
    //invalid if only one argument
    if(argc == 1)
        {
            printf("Invalid number of arguments");
            return 0;
        }

    char* ch;
    int len = strlen(argv[1]);
    int is_valid = 1;
    int count = 0;
    int upper = 0;  //keeps track of whether or not an uppercase was used
    int lower = 0;  //keeps track of whether or not a lowercase letter was used
        
    for(ch = argv[1]; ch < argv[1] + len; ch++)
    {
        if(!((*ch >= 'a' && *ch <= 'z') ||(*ch >= 'A' && *ch <= 'Z') || (*ch >= '0' && *ch <= '9')))
            is_valid = 0;
        if(*ch >= 'a' && *ch <= 'z')          //lower = 1 if a lowercase letter was used
            lower = 1;
        else if(*ch >= 'A' && *ch <= 'Z')     //upper = 1 if an uppercase letter was used
            upper = 1;
        count++;
    }

    if(count < 8 || upper == 0 || lower == 0)   //now checks if password is > 8 characters and contains an uppercase and lower case letter
        is_valid = 0;
    if(is_valid)
        printf("Valid");
    else printf("Invalid");
    
    return 0;
}
