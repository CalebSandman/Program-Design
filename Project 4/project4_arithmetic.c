/*
    Written by Caleb Sandman
    Project 4 for COP3514 Program Design

    This program takes a sequence of numbers, as an array, and returns whether it is an arithmetic sequence or not
*/

#include <stdio.h>

//function prototype
int is_arithmetic_sequence(int *sequence, int n);

//variable declarations
int sequence_length;
int is_sequence;

int main()
{
    //sequence length prompt
    printf("Enter length of the sequence: ");
    scanf("%d", &sequence_length);
    int sequence[sequence_length];

    //sequence elements prompt
    printf("Enter numbers of the sequence: ");
    for(int i = 0; i < sequence_length; i++)
        scanf("%d", &sequence[i]);

    //is_arithmetic_sequence call
    is_sequence = is_arithmetic_sequence(&sequence[0], sequence_length);
    if(is_sequence == 1)
        printf("yes");
    else
        printf("no");

    return 0;
}

int is_arithmetic_sequence(int *sequence, int n)
{
    int *end = sequence + n;
    int previous = *sequence; //[0]
    sequence++;
    int current = *sequence; //[1]
    int difference = current - previous;

    while(sequence < end)
    {
        if(current - previous != difference)
            return 0;
        previous = *sequence; //[n]
        sequence++; //n++
        current = *sequence; //[n] essentially [n+1]
    }
    return 1;
}