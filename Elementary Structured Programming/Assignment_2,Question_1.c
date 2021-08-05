#include <stdio.h>

int main(void)
{
    char x;

    printf("\nENTER AN UPPERCASE LETTER OR LOWER CASE LETTER OR A DIGIT: ");
    scanf("%c",&x);

    if(x>='a')
        if(x<='z')
            printf("\nIT IS A LOWER CASE LETTER.\n");
        else
            printf("\nI don't know.\n");

    else if(x>='A')
        if(x<='Z')
            printf("\nIT IS AN UPPER CASE LETTER\n");
        else
            printf("\nI don't know.\n");
    else if(x>='0')
        if(x<='9')
            printf("\nIT IS A DIGIT.\n");
        else
            printf("\nI don't know.\n");
    else
        printf("\nI don't know.\n");

    return 0;
}
