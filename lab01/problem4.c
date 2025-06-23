#include <stdio.h>

int main()
{
    int num[5] = {1, 3, 5, 4, 2};
    int *p1 = &num[0];
    int maxIndex = 0;
    for (int i = 0; i < 5; i++)
    {
        if (*(p1 + i) > *(p1 + maxIndex))
        {
            maxIndex = i;       // Find the maximum element
        }
    }
    int temp = *(p1 + maxIndex);        // Swap the two element
    *(p1 + maxIndex) = *(p1 + 4);
    *(p1 + 4) = temp;
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(p1 + i));
    }
    return 0;
}