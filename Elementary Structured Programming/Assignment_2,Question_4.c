#include <stdio.h>

int main(void)
{
    char x;

    printf("\nENTER A CHARACTER. ");
    scanf("%c",&x);

    if(x=='A'||x=='a'||x=='E'||x=='e'||x=='I'||x=='i'||x=='O'||x=='o'||x=='U'||x=='u')
        printf("\nIt is a vowel.\n");
    else if(x=='B'||x=='C'||x=='D'||x=='F'||x=='G'||x=='H'||x=='J'||x=='K'||x=='L'||x=='M'||x=='N'||x=='P'||x=='Q'||x=='R'||x=='S'||x=='T'||x=='V'||x=='W'||x=='X'||x=='Y'||x=='Z'||x=='b'||x=='c'||x=='d'||x=='f'||x=='g'||x=='h'||x=='j'||x=='k'||x=='l'||x=='m'||x=='n'||x=='p'||x=='q'||x=='r'||x=='s'||x=='t'||x=='v'||x=='w'||x=='x'||x=='y'||x=='z')
        printf("\nIt is a consonant.\n");
    else
        printf("\nI don't know.\n");

    return 0;
}
