#include <stdio.h>
#include <string.h>


int main()
{
    char str[301], str1[11], str2[11];
    scanf("%[^,],%[^,],%s", str, str1, str2);
    char* left_needle = strstr(str, str1);
    char* p = str, *right_needle = NULL;
    while ((p = strstr(p, str2)) != NULL)
    {
        right_needle = p;
        p++;
    }
    if (left_needle == NULL || right_needle == NULL 
        || left_needle + strlen(str1) > right_needle)
    {
        printf("-1");
        return 0;
    }
    else
    {
        printf("%d", right_needle - left_needle - strlen(str1));
        return 0;
    }
}