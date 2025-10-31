/*
    Written by Caleb Sandman
    Project 6 for COP3514 Program Design

    This program takes a file containing text (all lowercase, no more than 1000 items, and no more than 100 characters per item)
    Outputs a file with the items sorted in alphabetical order

    This may be more complicated than it needs to be
    Possibly due to my use of pointers
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

//function prototype
void selection_sort(char items[][MAX_LENGTH + 1], int n);

int main(int argc, char *argv[])
{
    char str[1000][MAX_LENGTH + 1] = {"."}; //2D array to hold text. Initialized with "." so the rest of the array is auto filled with null
    char (*p)[MAX_LENGTH + 1] = str; //pointer to the strings in str, starts at the first string
    
    //file pointers
    FILE* inFile;
    FILE* outFile;

    inFile = fopen(argv[1], "r"); //opens 2nd argument in read mode
    outFile = fopen(argv[2], "w"); //opens 3rd argument in write mode

    //gets each line from inFile and stores it in the 2D array str
    while(fgets(*p, MAX_LENGTH + 1, inFile) != NULL)
    {
        p++;
    }

    selection_sort(str, 1000); //call to sort str

    //outs each item into outFile
    for(p = str; p < str + 1000; p++)
    {
        fputs(*p, outFile);
    }

    //close files
    fclose(inFile);
    fclose(outFile);

    return 0;
}

void selection_sort(char items[][MAX_LENGTH + 1], int n) //takes pointer to 2D array, number of rows
{
    char (*s)[MAX_LENGTH + 1], (*t)[MAX_LENGTH + 1]; //pointers to strings
    char temp[MAX_LENGTH + 1]; //temp string for swapping

    /*
    starts at the first string and compares every string after
    this ensures the first string alphabetically is at the top

    process is repeated leaving all strings in alphabetical order
    */
    for(s = items; s < items + n; s++) //iterates through each string starting at the first. Remember, item points to a 2D array so *item is the first string
    {
        for(t = s + 1; t < items + n; t++) //iterates through each string starting at the second (next string from the previous loop)
        {
            //if the current string is greater then the next, swap them
            if(strcmp(*s, *t) > 0)
            {
                strcpy(temp, *s);
                strcpy(*s, *t);
                strcpy(*t, temp);
            }
        }
    }
}