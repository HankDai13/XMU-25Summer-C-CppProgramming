#include <stdio.h>
#define N 7

// 使用指针移动法实现数组逆序重排
void reverse_array(int *arr, int size) {
    int *p1 = arr;              // 指向数组首元素
    int *p2 = arr + size - 1;   // 指向数组末元素
    int temp;
    
    // 通过移动指针交换元素，直到指针相遇
    while (p1 < p2) {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;    // 指针向后移动
        p2--;    // 指针向前移动
    }
}

void print_array(int *arr, int size) {
    int *p = arr;  // 用指针遍历数组
    for (int i = 0; i < size; i++) {
        printf("%d ", *p);
        p++;  // 指针移动到下一个元素
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
