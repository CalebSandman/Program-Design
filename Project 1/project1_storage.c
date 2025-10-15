/*
    Written by Caleb Sandman
    Project 1 for COP3514 Program Design
    
    This program calculates the cost for storage based on the number of months the storage is needed
*/

#include <stdio.h>

int main()
{
    //initialization of variables
    int first_month;
    int monthly_rate;
    int yearly_max;
    int size_input;
    int months_input;
    int total;

    //prompt for user input and shows dimensions of storage options
    printf("Please select from four types of storages: 1, 2, 3, and 4\n");

    //user input for size
    printf("Enter storage selection:");
    scanf("%d", &size_input);
    if(size_input < 1 || size_input > 4)    //if not in range exit application
    {
        printf("Invalid size. Select from 1 to 4.");
        return 0;
    }

    //user input for months
    printf("Enter months:");
    scanf("%d", &months_input);
    if(months_input < 1)    //if not <= 1 exit application
    {
        printf("Invalid months.");
        return 0;
    }

    //set values for first_month, monthly_rate, and yearly_max according to selected size
    switch (size_input)
    {
        case 1: //5x5
            first_month = 0;
            monthly_rate = 40;
            yearly_max = 400;
            break;
        
        case 2: //5x10
            first_month = 25;
            monthly_rate = 50;
            yearly_max = 500;
            break;

        case 3: //10x10
            first_month = 40;
            monthly_rate = 100;
            yearly_max = 800;
            break;

        case 4: //10x15
            first_month = 60;
            monthly_rate = 150;
            yearly_max = 1200;
            break;
    }

    //calculate the total cost
    if(months_input >= 12) //if there is atleast one full year
    {
        total = (months_input / 12) * yearly_max;                           //adds the yearly max for each full year

        //checks if cost of remaining months goes over the yearly max and adds accordingly
        if((months_input % 12) * monthly_rate >= yearly_max)                //cost is greater or equal than yearly max
            total += yearly_max;
        else                                                                //cost is less than yearly max
            total += (months_input % 12) * monthly_rate;
    }
    else //if there are no full years
    {
          //checks if cost goes over the yearly max and adds accordingly
        if((months_input - 1) * monthly_rate >= yearly_max)                 //cost is greater or equal than yearly max
            total = yearly_max;
        else                                                                //cost is less than yearly max
            total = first_month + (months_input - 1) * monthly_rate;
    }

    //print the total cost
    printf("Charge($):%d", total);

    //breaks from main function
    return 0;
}