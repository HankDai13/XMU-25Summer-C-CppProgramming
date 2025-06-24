#include <stdio.h>
#include <string.h>

int is_single(int map[26])
{
    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        if (map[i] > 0)
        {
            flag++;
        }
    }
    if (flag > 1) return 0;
    else return 1;
}
char get_mapchar(int map[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (map[i] > 0)
        {
            return 'a' + i;
        }
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++)
    {
        int flag = 1;
        int map[26][26] = {0};
        char s1[101], s2[101];
        scanf("%s %s", s1, s2);
        for (int i = 0; i < strlen(s1); i++)
        {
            map[s1[i] - 'a'][s2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (is_single(map[i]) == 0)
            {
                flag = 0;
            }
        }
        if (flag == 0)
        {
            printf("false\n");
        }
        else
        {
            for(int i = 0; i < strlen(s1); i++)
            {
                s1[i] = get_mapchar(map[s1[i] - 'a']);
            }
            if (strcmp(s1, s2) == 0)
            {
                printf("true\n");
            }
            else
            {
                printf("false\n");
            }
        }
    }   
}