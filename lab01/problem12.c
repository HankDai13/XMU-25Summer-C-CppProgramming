#include <stdio.h>


int uniquePathsWithObstacles(int* obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize)
{
    int m = obstacleGridRowSize, n = obstacleGridColSize;
    int dp[m][n];
    int toPath = 1;
    for (int i = 0; i < m; i++)
    {
        if (obstacleGrid[i * n] == 1)
        {
            toPath = 0;
        }
        dp[i][0] = toPath;
    }
    toPath = 1;
    for (int j = 0; j < n; j++)
    {
        if (obstacleGrid[j] == 1)
        {
            toPath = 0;
        }
        dp[0][j] = toPath;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[i * n + j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}
int main(){
	int a[3][3] = {0,0,0,0,1,0,0,0,0};
	int k = uniquePathsWithObstacles(a[0],3,3);
	printf("There are %d paths\n",k);
	return 0;
}
