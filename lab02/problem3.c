#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int xnum[n + 1];
    memset(xnum, 0, sizeof(xnum));
    int flag = 0;
    char line[n + 1];
    scanf("%s", line);
    for(int i = 0; i <= n; i++)
    {
        if (flag != 0 && (line[i] != 'x' || i == n))
        {
            xnum[flag]++;
            flag = 0;
            
        }
        else if (line[i] == 'x')
        {
            flag++;
        }
    }
    int sum = 0;
    for (int i = 3; i < n + 1; i++)
    {
        sum += (i - 2) * xnum[i];
    }
    printf("%d", sum);
}