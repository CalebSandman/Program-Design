/*
    Written by Caleb Sandman
    Project 2 for COP3514 Program Design

    This program takes a user input of coins (nickles, dimes, and quarters) as well as an option for cup size
    It takes the price and input and calculates the change due
*/

#include <stdio.h>

int main()
{
    //defining small and large cup prices
    #define SMALL 75
    #define LARGE 125

    //variable initialization
    int total_coins = 0;
    int coins;
    int size;
    int change = 0;

    //user input for coins. Ends when 0 is entered
    do
    {
        printf("Insert coins: ");
        scanf("%d", &coins);
        total_coins += coins;
    } while (coins != 0);

    //prompt for small cup ('1') or lage cup ('2')
    printf("Please select 1 for a small cup and 2 for a large cup: ");
    scanf("%d", &size);

    //calculate change based on cup size
    switch(size)
    {
        //small cup
        case 1:
            change = total_coins - SMALL;
            break;
        
        //large cup
        case 2:
            change = total_coins - LARGE;
            break;
    }

    //exit message and change amount
    if(change < 0)	//display if insufficient ammount of change
    {
        printf("Insufficient amount.\n");
        printf("Your change is %d cents. Collect your change at the bottom.", total_coins);
    }
    else if(change > 0)	//display if there is change
    {
        printf("Collect your juice and enjoy!\n");
        printf("Your change is %d cents. Collect your change at the bottom.", change);
    }
    else		//display if no change
    {
        printf("Collect your juice and enjoy!\n");
    }

    return 0;
}
