#include <stdio.h>

int uniquePaths(int m, int n)
{
    if (m == 1 || n == 1)
    {
        return 1;
    }
    else if (m < 1 || n < 1)
    {
        return 0;
    }
    int uniquePathsRight = 0, uniquePathsDown = 0;
    uniquePathsRight = uniquePaths(m - 1, n);
    uniquePathsDown = uniquePaths(m, n - 1);
    return uniquePathsDown + uniquePathsRight;
}
int main()
{
    int m = 3, n = 2;
    int k = uniquePaths(m, n);
    printf("There are %d paths\n", k);
    return 0;
}