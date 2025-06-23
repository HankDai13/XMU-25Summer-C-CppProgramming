#include <stdio.h>

int main()
{
    int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
    int *p1 = a[0];
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", *p1);
        p1++;
    }
    return 0;
}