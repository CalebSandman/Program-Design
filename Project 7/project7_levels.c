/*
    Written by Caleb Sandman
    Project 7 for COP3514 Program Design

    This program is meant to read a SCV file, of a user given name, that contains student info
    first name (string),  last name (string), points (int)
    With each student on a seperate line

    Outputs a CSV file with the values
    first name (string),  last name (string), points (int), level (int)
    With each student on a seperate line
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_STUDENTS 1000

//student structure definition
struct student
    {
        char first_name[MAX_LENGTH + 1], last_name[MAX_LENGTH + 1];
        int points, level;
    };

//function prototypes
int read_line(char* str, int n);
void assign_level(struct student list[], int n);

int main()
{
    //get input file name
    char in_file_name[MAX_LENGTH + 1];
    printf("Enter file name: ");
    read_line(in_file_name, MAX_LENGTH);

    //open input file in read mode and output file in write mode
    FILE* inFile = fopen(in_file_name, "r");
    FILE* outFile = fopen("result.csv", "w");

    //array of up to 1000 students
    struct student class[MAX_STUDENTS];
    int i = 0; //class index

    while(!feof(inFile) && !ferror(inFile)) //while not at end of file and no errors
    {
        if(fscanf(inFile, "%[^,],%[^,],%d\n", class[i].first_name, class[i].last_name, &class[i].points) == 3) //scanned first name, last name, and points
        {
            assign_level(class, i);
            fprintf(outFile, "%s, %s, %d, %d\n", class[i].first_name, class[i].last_name, class[i].points, class[i].level);
            i++;
        }
    }

    //close files
    fclose(inFile);
    fclose(outFile);

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




void assign_level(struct student list[], int n)
{
    if(list[n].points <= 50)
        list[n].level = 1;
    else if(list[n].points <= 95)
        list[n].level = 2;
    else
        list[n].level = 3;
}