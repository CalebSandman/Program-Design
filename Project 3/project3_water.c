/*
    Written by Caleb Sandman
    Project 3 for COP3514 Program Design

    This program takes an input for water usage (in units of 1000 gallons) for the current month and the usage for the past 10 months
    Returns if the current month's water usage is unusual (greater than 2 standard deviations)
*/

#include <stdio.h>
#include <math.h>


//function prototypes
double average(double usage[], int n);
double standard_deviation(double usage[], double avg, int n);

int main()
{
    //variable declaration
    double mean;
    double deviation;
    double past_10[10];
    double current;

    //user input
    printf("Enter water usage for this month: ");
    scanf("%lf", &current);
    printf("Enter water usage for the last 10 months: ");
    for(int i = 0; i < 10; i ++)
    {
        scanf("%lf", &past_10[i]);
    }

    //function calls for mean and standard deviation
    mean = average(past_10, 10);
    deviation = standard_deviation(past_10, mean, 10);

    if(current > mean + (2 * deviation))
        printf("Unusual usage.");
    else
        printf("Normal usage.");

    return 0;
}

//takes a double array and the array's length
//returns the average of the doubless in the array
double average(double usage[], int n)
{
    double sum = 0;
    for(int i; i < n; i++)
    {
        sum += usage[i];
    }

    return sum / n;
}

//takes a double array and the array's length
//returns the standard deviation
double standard_deviation(double usage[], double avg, int n)
{
    double dev = 0;
    for(int i = 0; i < n; i++)
    {
        dev += pow(usage[i] - avg, 2);
    }
    dev /= n - 1;
    
    return sqrt(dev);
}
