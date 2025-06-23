#include <stdio.h>

// 方法一：递归返回值
float fac(int n)
{
    if (n > 1)
    {
        return n * fac(n - 1);
    }
    else if (n == 1 || n == 0)  // 添加 n == 0 的情况
    {
        return 1;
    }
    else
    {
        return 0;  // 处理负数情况
    }
}

// 方法二：通过指针传递结果
void fac2(int n, float* k)
{
    if (n <= 1)
    {
        *k = 1;  // 基础情况：0! = 1! = 1
    }
    else
    {
        fac2(n - 1, k);  // 先计算 (n-1)!
        *k = *k * n;     // 然后乘以 n
    }
}

int main()
{ 
    int m;
    float k;
    printf("input m:");
    scanf("%d",&m);
    
    k = fac(m);
    printf("result=%f", k);
    
    printf("\nAnother method:\n");
    k = 0;
    fac2(m, &k);
    printf("result=%f\n", k); 
    
    return 0;
}
