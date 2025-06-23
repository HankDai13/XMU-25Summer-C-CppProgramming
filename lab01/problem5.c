#include <stdio.h>
#define N 7

// 使用指针（首地址偏移法）实现数组逆序重排
void reverse_array(int *arr, int size) {
    int *start = arr;           // 指向数组首元素
    int *end = arr + size - 1;  // 指向数组末元素
    int temp;
    
    // 交换首尾元素，直到指针相遇
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// 打印数组函数
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));  // 使用首地址偏移法访问元素
    }
    printf("\n");
}

int main()
{
    int a[N] = {1, 2, 3, 4, 11, 12, 13};
      printf("Original array: ");
    print_array(a, N);
    
    reverse_array(a, N);
    
    printf("Reversed array: ");
    print_array(a, N);
    
    return 0;
}