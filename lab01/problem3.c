#include <stdio.h>

int main()
{
    int a[ ][4]={0,1,2,3,1,4,5,6,2,5,7,8,3,6,8,9};
    int found = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (a[i][j] != a[j][i])
            {
                found = 0;
            }
        }
    }
    if (found==0) printf("no\n");
    else printf("yes\n");
    return 0;
}