/*Write a multifunction C program to calculate and display the total salary of an employee considering that total salary
is the sum of basic salary and house rent. The program must ask in 'main' for the basic salary and percentage of basic
salary which determines the house rent*/

#include<stdio.h>

float sal_calc(float x,float y);
int main(void)
{
    float bs,hrp,salary;

    printf("\nENTER THE BASIC SALARY (in taka): ");
    scanf("%f",&bs);
    printf("\nENTER THE PERCENTAGE OF HOUSE RENT (in taka): ");
    scanf("%f",&hrp);

    salary=sal_calc(bs,hrp);
    printf("\nTOTAL SALARY: %f TAKA",salary);

    return 0;
}

float sal_calc(float x,float y)
{
    float total_salary;
    total_salary=x+(x*y/100);

    return total_salary;
}
