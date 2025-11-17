/*
    Modified by Caleb Sandman
    Project 8 for COP3514 Program Design

    Program is for creating a list of tutors with a last name, first name, email, and three preferences (represented by 0 or 1)
    User functions allow adding a tutor, searching for and printing all tutors with a specific preference, and printing all tutors
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EMAIL_LEN 100
#define NAME_LEN 30
#define LEVEL_LEN 30

struct tutor
{
    char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];
	int preferences[3];
	struct tutor *next;
};


struct tutor *add_to_list(struct tutor *list);
void search_list(struct tutor *list);
void print_list(struct tutor *list);
void clear_list(struct tutor *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(){
    char code;

    struct tutor *tutor_list = NULL;  
    printf("Operation Code: a for adding to the list, s for searching"
	    ", p for printing the list; q for quit.\n");
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

struct tutor *add_to_list(struct tutor *list){

    struct tutor *cur, *new_node;

	new_node = malloc(sizeof(struct tutor));
	if(new_node == NULL)
    {
	    printf("Database is full.\n");
		return list;
	}

	printf("Enter last name: ");
	read_line(new_node->last, NAME_LEN);
	printf("Enter first name: ");
	read_line(new_node->first, NAME_LEN);
  	printf("Enter email address: ");
  	read_line(new_node->email, EMAIL_LEN);
	printf("Enter preferences: ");
 	scanf("%d %d %d", &new_node->preferences[0], &new_node->preferences[1], &new_node->preferences[2]);

    struct tutor *p;
    for(p = list; p != NULL; p = p->next) //p points to the first node; if the node has allocated space; p points to the next node
    {
        if(strcmp(new_node->last, p->last) == 0 && strcmp(new_node->email, p->email) == 0) //if the node we're creating and the node p points to have the same last name and email
        {
            printf("tutor already exists.\n");
            free(new_node); //frees the space of the new node
            return list; //returns the original list, nothing added
        }
    }

    new_node->next = NULL; //next node will be NULL because this node will be added to the end
    if(list == NULL)
        return new_node;

    cur = list; //cur points to the first node
    while(cur->next != NULL) //while cur is not the last node
        cur = cur->next; //cur becomes the next node
    cur->next = new_node; //the new node becomes the last node

    return list;
}


//prints all tutors' name and email of a specific level ("elemantary", "middle", or "high")
void search_list(struct tutor *list)
{
	char level[LEVEL_LEN+1];;
	printf("Enter level: ");
	read_line(level, LEVEL_LEN+1);

    //assigns preferences index based off level
    int pref_index;
    if(strcmp(level, "elementary") == 0)
        pref_index = 0;
    else if(strcmp(level, "middle") == 0)
        pref_index = 1;
    else
        pref_index = 2;

    //print all tutors at the specified level
    struct tutor *p;
    int preference_exists = 0;
    for(p = list; p != NULL; p = p->next)
    {
        if(p->preferences[pref_index] != 0)
        {
            printf("%s %s %s\n", p->last, p->first, p->email);
            preference_exists = 1;
        }
    }

    if(preference_exists == 0)
        printf("not found\n");
}


//prints all info of all tutors
void print_list(struct tutor *list)
{
    struct tutor *p;
    for(p = list; p != NULL; p = p->next)
    {
        printf("%-12s%-12s%-30s%5d%5d%5d\n", p->last, p->first, p->email, p->preferences[0], p->preferences[1], p->preferences[2]);
    }
}


//deallocates memory of the entire list
void clear_list(struct tutor *list)
{
    struct tutor *p; //pointer to tutor structure
    while(list != NULL)
    {
        p = list; //p points to first node
        list = list->next; //the second node is now considered the first node
        //clears the previous first node
        if(p != NULL)
            free(p);
    }
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}