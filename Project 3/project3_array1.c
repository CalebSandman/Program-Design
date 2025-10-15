/*
    Written by Caleb Sandman
    Project 3 for COP3514 Program Design

    This program takes an int array as input and checks if the elements are in ascending order and if each element is NOT divisible by the previous
*/

#include <stdio.h>

int main()
{
    int length;

    //request array length and declare an array "arr" of inputed length
    printf("Enter the length of the input array: ");
    scanf("%d", &length);
    int arr[length];

    //requests array elements and assigns them to the array in inputed order while checking if the proper conditions hold
    printf("Enter the array elements: ");
    for(int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);

        //checks that every element is greater than the previous and aren't divisible by the previous
        if(i != 0 && (arr[i] <= arr[i-1] || arr[i] % arr[i-1] == 0))
        {
            printf("Output: no");
            return 0;
        }
    } 

    //array conditions held
    printf("Output: yes");
    return 0;
}