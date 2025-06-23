#include <stdio.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < 4; i++)  // 外层循环只需要n-1次
    {
        int swapped = 0;  // 提前终止优化
        for (int j = 0; j < 4 - i; j++)  // 内层循环范围逐渐减少
        {
            if (a[j] < a[j + 1])  // 相邻元素比较
            {
                swap(&a[j], &a[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break;  // 如果没有交换，说明已经有序
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}