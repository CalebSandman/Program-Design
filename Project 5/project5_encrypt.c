/*
    Written by Caleb Sandman
    Project 5 for COP3514 Program Design

    This program takes a string input and encrypts it by moving the letters based on a date's digits
*/

#include <stdio.h>
#include <string.h>

//function prototypes
int read_line(char* str, int n);
void encrypt(char* str, int length, int* date);

#define STR_LENGTH 1000 //max message length

int main()
{
    //variable declarations
    char msg[STR_LENGTH + 1];
    int num_characters;
    int date[8];
    int* p;

    //msg[] holds the inputted text and num_characters holds the number of characters
    printf("Enter the message: ");
    num_characters = read_line(msg, STR_LENGTH);

    //stores each number of the date in the array date[]
    printf("Enter date in the format of 8 digits: ");
    for(p = date; p < date + 8; p++)
        scanf("%1d", p);

    //encrypts the message and prints it
    encrypt(msg, num_characters, date);
    printf("%s", msg);

    return 0;
}

int read_line(char* str, int n)
{
    int ch, i = 0;
    while((ch = getchar()) != '\n')
        if (i < n)
        {
            *str++ = ch;
            i++;
        }

    *str = '\0'; //terminates string
    return i; //number of characters stored
}

void encrypt(char* str, int length, int* date)
{
    char* p; //points to str character
    int* q = date; //points to date character

    //loops through each character is the string
    for(p = str; p < str + length; p++)
    {
        if('a' <= *p && *p <= 'z') //character is lowercase
        {
            *p = (((*p - 'a') + *q) % 26) + 'a';
        }
        else if('A' <= *p && *p <= 'Z') //character is uppercase
        {
            *p = (((*p - 'A') + *q) % 26) + 'A';
        }
        else //character is not aplhabetical
            continue;

        q++;
        //returns to the start of date if at end
        if(q - 8 == date)
            q -= 8;
    }
}