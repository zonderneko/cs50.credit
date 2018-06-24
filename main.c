#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int summ(int array[]);
int check(char s[], int lim);
int main()
{
    int a = 0, i = 0, j = 0, c = 0, l = 0, chk = 0, q = 0, z = 0, x = 0;
    char card_num [16];
    int first [8];
    int seconds [8];
    do                                          //check cycle
    {
        printf ("Enter card number:\n");
        scanf("%s", card_num);
        c = strlen(card_num);
        if (c < 13 || c > 16 || check(card_num, c) == 0)
            printf("Retry\n");
    }
    while (c < 13 || c > 16 || check(card_num, c) == 0);
    c = strlen(card_num);
    if (c < 16)                     //fill 13+ strings to 16 with zeroes
    {
        for (i = c; i < 16; i++)
            card_num[i] = '0';
    }
    for (i = 0; i < 16; i++)
    {
        a = card_num[i] - '0';
        if (i % 2)
        {
            seconds[j] = a * 2;
            j++;
        }
        else
        {
            first [l] = a;
            l++;
        }
    }
    chk = (summ(first) + summ(seconds)) % 10;
    z = card_num[0] - '0';
    x = card_num[1] - '0';
    if (z == 3 && (x == 4 || x == 7) && c == 15)
        q = 1;
    else if (z == 5 && x > 0 && x < 6 && c == 16)
        q = 2;
    else if (z == 4 && (c == 13 || c == 16))
        q = 3;
//           printf ("Lenght %i, State %i\n",c,q);
    if (chk == 0)
    {
        switch (q)
        {
        case 1:
            printf("AmEx\n");
            break;
        case 2:
            printf("Maestro\n");
            break;
        case 3:
            printf("VISA\n");
            break;
        default:
            printf("Incorrect_card?");
            break;
        }
    }
    else
        printf("INVALID");
}
int summ (int array[])
{
    int k = 0, b = 0;
    for (k = 0; k < 8; k++)
    {
        if (array[k] < 10)
            b = b + array[k];
        else
            b = b + 1 + array[k] % 10;
    }
    return b;
}
int check (char s[], int lim)
{
    int i = 0, r = 1;
    for (i=0; i < lim; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            r = 0;
    }
    return r;
}
