#include <stdio.h>

char* strcat(char* str1, char* str2)
{
    // Assume that str1 is big enough
    char *p1 = str1, *p2 = str2;
    while (*p1 != '\0')
    {
        p1++;
    }
    while (*p2 != '\0')
    {
        *p1 = *p2;
        p1++;
        p2++;
    }
    *p1 = '\0';
    return str1;
}
int main()
{
    char str1[30] = "I learn ", *str2 = "C language.";
    char *s;
    s = strcat(str1,str2);
    //strcat函数的返回值是指针      
    printf("%s\n", s); 
}