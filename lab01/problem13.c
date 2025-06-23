#include <stdio.h>

void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void rotate(int* matrix, int matrixRowSize, int matrixColSize)
{
    //补充函数，实现原地旋转功能
    int n = matrixRowSize;  
    
    // 转置
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(&matrix[i*n + j], &matrix[j*n + i]);
        }
    }
    
    // 翻转每一行
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2; j++) {
            // 交换 matrix[i][j] 和 matrix[i][n-1-j]
            swap(&matrix[i*n + j], &matrix[i*n + n-1-j]);
        }
    }
}

int main(){
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    rotate(a[0],3,3);
      
    int *p; 
    for(p=a[0];p<a[0]+9;p++) 
    { 
        
        if((p-a[0])%3==0) printf("\n"); 

        printf("%4d",*p); 
     } 
    return 0;
}