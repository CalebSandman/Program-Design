/*
    Written by Caleb Sandman
    Project 5 for COP3514 Program Design

    This program takes a string input and encrypts it by moving the letters based on a date's digits
*/

#include <stdio.h>
#include <string.h>

//function prototypes
int read_line(char* str, int n);
void encrypt(char* message, char* encrypted_message, int* date, int n);

#define MAX_LENGTH 1000 //max message length

int main()
{
    //variable declarations
    char msg[MAX_LENGTH + 1];
    char enc_msg[MAX_LENGTH + 1];
    int num_characters;
    int date[8];
    int* p;

    //msg[] holds the inputted text and num_characters holds the number of characters
    printf("Enter the message: ");
    num_characters = read_line(msg, MAX_LENGTH);
    enc_msg[num_characters] = '\0';

    //stores each number of the date in the array date[]
    printf("Enter date in the format of 8 digits: ");
    for(p = date; p < date + 8; p++)
        scanf("%1d", p);

    //encrypts the message and prints it
    encrypt(msg, enc_msg, date, 8);
    printf("%s", enc_msg);

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

void encrypt(char* message, char* encrypted_message, int* date, int n)
{
    char* p; //points to message character
    int* q; //points to date character
    char* s; //points to encrypted_message character

    //loops through each character is the string
    for(p = message, q = date, s = encrypted_message; p < message + strlen(message); p++, s++)
    {
        if('a' <= *p && *p <= 'z') //character is lowercase
        {
            *s = (((*p - 'a') + *q) % 26) + 'a';
        }
        else if('A' <= *p && *p <= 'Z') //character is uppercase
        {
            *s = (((*p - 'A') + *q) % 26) + 'A';
        }
        else //character is not aplhabetical
        {
            *s = *p;
            continue;
        }
        q++;

        //returns to the start of date if at end
        if(q - n == date)
            q -= n;
    }
}