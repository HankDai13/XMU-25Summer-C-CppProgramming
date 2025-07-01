#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10;
char str[N];
char out[N];
int used[N];

int len;

void dfs(int u)
{
    if (u == len)
    {
        out[len] = '\0';
        cout << out << endl;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            if (!used[i])
            {
                used[i] = 1;
                out[u] = str[i];
                dfs(u + 1);
                used[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> str;
    len = strlen(str);
    sort(str, str + len);
    dfs(0);
}