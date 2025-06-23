#include <stdio.h>

void spiralOrder(int* matrix, int matrixRowSize, int matrixColSize, int* result){
    int top = 0, bottom = matrixRowSize - 1;
    int left = 0, right = matrixColSize - 1;
    int index = 0;
    
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            result[index++] = matrix[top * matrixColSize + j];
        }
        top++;  // 上边界下移
        
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i * matrixColSize + right];
        }
        right--;  // 右边界左移
        
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[index++] = matrix[bottom * matrixColSize + j];
            }
            bottom--;  // 下边界上移
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i * matrixColSize + left];
            }
            left++;  // 左边界右移
        }
    }
}

int main(){
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    int matrixRowSize=3,matrixColSize=3;
    int returnnum[9];
    spiralOrder((int*)a, matrixRowSize, matrixColSize, returnnum);
    
    printf("spiralOrderOutput: ");
    int *p;
    for(p=returnnum; p<returnnum+9; p++) 
    { 
        printf("%4d",*p); 
    } 
    printf("\n");
    return 0;
}