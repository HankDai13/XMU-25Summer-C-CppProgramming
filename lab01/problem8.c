#include <stdio.h>

int main()
{
    int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23}; 
    
    // 定义行指针，指向二维数组的行
    int (*row_ptr)[4] = a;  // 指向第一行
      printf("Using row pointer to output 2D array elements:\n");
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", (*(row_ptr + i))[j]);
        }
        printf("\n");
    }
    return 0;
}