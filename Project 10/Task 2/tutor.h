#ifndef TUTOR_H
    #define TUTOR_H

    #define EMAIL_LEN 100
    #define NAME_LEN 30
    #define LEVEL_LEN 30

    //function prototypes
    struct tutor
    {
        char first[NAME_LEN+1];
        char last[NAME_LEN+1];
        char email[EMAIL_LEN+1];
        int preferences[3];
        struct tutor *next;
    };


    struct tutor *add_to_list(struct tutor *list);
    struct tutor *delete_from_list(struct tutor *list);
    void search_list(struct tutor *list);
    void print_list(struct tutor *list);
    void clear_list(struct tutor *list);

#endif