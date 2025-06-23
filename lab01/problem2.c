#include <stdio.h>

int main()
{
    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
      // 打印原始矩阵
    printf("Original matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            // 交换 a[i][j] 和 a[j][i]
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
      // 打印转置后的矩阵
    printf("\nTransposed matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}