/*
    Modified by Caleb Sandman
    Project 10 for COP3514 Program Design

    Program is for creating a list of tutors with a last name, first name, email, and three preferences (represented by 0 or 1)
    User functions allow adding a tutor, searching for and printing all tutors with a specific preference, and printing all tutors

    Keeps the delete function and modified add function from the previous version (Project 9)

    This version has split the program into three source files and two header files
*/

#include <stdio.h>
#include "tutor.h"
#include "read_line.h"


/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main()
{
    char code;

    struct tutor *tutor_list = NULL;  
    printf("Operation Code: a for adding to the list, s for searching, d for deleting from the list, p for printing the list; q for quit.\n");
    for (;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n'); /* skips to end of line */
        switch (code) 
        {
            case 'a': 
                tutor_list = add_to_list(tutor_list);
                break;
            
            case 'd':
                tutor_list = delete_from_list(tutor_list);
                break;

            case 's': 
                search_list(tutor_list);
                break;

            case 'p': 
                print_list(tutor_list);
                break;

            case 'q': clear_list(tutor_list);
                return 0;

            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}


