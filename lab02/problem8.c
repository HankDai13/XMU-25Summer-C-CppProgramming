#include <stdio.h>
#include <string.h>

void swap(char* p1, char* p2)
{
    char temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int c = 0; c < C; c++)
    {
        char str[51];
        scanf("%s", str);
        for (int i = 0; i < strlen(str); i+=2)
        {
            swap(&str[i], &str[i + 1]);
        }
        printf("%s\n", str);
    }
}