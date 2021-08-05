/*Write a program that receives with appropriate prompts "one whole number" and one "decimal fraction" from keyboard.
It must display the received numbers and their sum in a single line output.

        INPUT                                                     OUTPUT
Enter one whole number: 5                              The sum of 5 and 9.1 is 14.1
Enter one decimal fraction number: 9.1                                                                            */

#include<stdio.h>

int main(void)
{
    int i;
    float f,s;
     printf("Enter one whole number: ");
     scanf("%d",&i);

     printf("Enter one decimal fraction number: ");
     scanf("%f",&f);

     s=i+f;

     printf("The sum of %d and %f is %f",i,f,s);

     return 0;
}
