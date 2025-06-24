#include <stdio.h>
#include <string.h>

int main()
{
    char line[101];
    int sum = 0;
    if (fgets(line, sizeof(line), stdin) == NULL) return 0;
    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            sum++;
        }
    }
    printf("%d", sum);
}