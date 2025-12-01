#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tutor.h"
#include "read_line.h"

//function definitions
struct tutor *add_to_list(struct tutor *list)
{
    struct tutor *cur, *new_node, *prev;

    //allowcate space for new node
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

    for(cur = list; cur != NULL; cur = cur->next) //cur points to the first node; if the node has allocated space; cur points to the next node
    {
        if(strcmp(new_node->last, cur->last) == 0 && strcmp(new_node->email, cur->email) == 0) //if the node we're creating and the node cur points to have the same last name and email
        {
            printf("tutor already exists.\n");
            free(new_node); //frees the space of the new node
            return list; //returns the original list, nothing added
        }
    }

    cur = list; //reset cur back to the start of the list
    new_node->next = NULL; //next node will be NULL because this node will be added to the end
    if(list == NULL)
        return new_node;

    /*loop until at desired node
        breaks when:
        cur == NULL; at the end of list
        new_node->last < cur->last; new last name is less than cur's last name
        new_node->last == cur->last AND new_node->first < cur->first; last names are the same and new first name is less than cur's first name
    */
    for(cur = list, prev = NULL; cur != NULL && strcmp(new_node->last, cur->last) >= 0 && (strcmp(new_node->last, cur->last) != 0 || strcmp(new_node->first, cur->first) >= 0); prev = cur, cur = cur->next);

    new_node->next = cur;
    if(prev == NULL) //if new node is at the start
        return new_node;
    
    prev->next = new_node;
    return list;
}




//deletes a tutor from the list
struct tutor *delete_from_list(struct tutor *list)
{
    struct tutor *cur, *prev;
    char last_name[NAME_LEN + 1], first_name[NAME_LEN + 1], email_address[EMAIL_LEN + 1];

    //if list is empty return null
    if(list == NULL)
        return NULL;

    printf("Enter last name: ");
    read_line(last_name, NAME_LEN);
    printf("Enter first name: ");
    read_line(first_name, NAME_LEN);
    printf("Enter email address: ");
    read_line(email_address, EMAIL_LEN);

    /*find the node with specified name
        breaks when:
        cur == NULL; at the end of list
        cur->last == last_name AND cur->first == first_name AND cur->email == email_address; both names and email matches what user wants to delete
    */
    for(cur = list, prev = NULL; cur != NULL && (strcmp(cur->last, last_name) != 0 || strcmp(cur->first, first_name) != 0 || strcmp(cur->email, email_address) != 0); prev = cur, cur = cur->next);

    //cur will equal null if tutor did not exist
    if(cur == NULL)
    {
        printf("tutor does not exist");
        return list;
    }
    //if deletion node was the first node list starts at the second node
    if(prev == NULL)
        list = list->next;
    else //deletion node was not the first node
        prev->next = cur->next; //previous node's next becomes deleted node's next
    free(cur);
    printf("tutor deleted");
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
    struct tutor *cur;
    int preference_exists = 0;
    for(cur = list; cur != NULL; cur = cur->next)
    {
        if(cur->preferences[pref_index] != 0)
        {
            printf("%s %s %s\n", cur->last, cur->first, cur->email);
            preference_exists = 1;
        }
    }

    if(preference_exists == 0)
        printf("not found\n");
}




//prints all info of all tutors
void print_list(struct tutor *list)
{
    struct tutor *cur;
    for(cur = list; cur != NULL; cur = cur->next)
    {
        printf("%-12s%-12s%-30s%5d%5d%5d\n", cur->last, cur->first, cur->email, cur->preferences[0], cur->preferences[1], cur->preferences[2]);
    }
}




//deallocates memory of the entire list
void clear_list(struct tutor *list)
{
    struct tutor *cur; //pointer to tutor structure
    while(list != NULL)
    {
        cur = list; //cur points to first node
        list = list->next; //the second node is now considered the first node
        //clears the previous first node
        if(cur != NULL)
            free(cur);
    }
}
