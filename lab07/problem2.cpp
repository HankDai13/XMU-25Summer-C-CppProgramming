#include <iostream>
#include <vector>
#include <string>
using namespace std;

void get_next(vector<int>& next, string p)
{
    int n = p.size();
    next.resize(n + 1);
    next[0] = 0;
    if (n > 0) next[1] = 0;
    for(int j = 2, i = 0; j <= n; j++)
    {
        while(i > 0 && p[i] != p[j - 1]) i = next[i];
        if(p[i] == p[j - 1]) i++;				 
        next[j] = i;			
    }
}

vector<int> kmp(string s, string p, vector<int>& next)
{
    vector<int> res;	// 保存 p 在 s 中出现的位置的索引
    for(int i = 0, j = 0; i < s.size(); i++)
    {
        while(j > 0 && s[i] != p[j]) j = next[j];	// 匹配失败 调整 j 的位置
        if(s[i] == p[j]) j++;			// 匹配成功 j++ 继续匹配 
        if(j == p.size())			// j到了子串p末尾，说明 完全匹配到了一个答案，记录结果，然后继续调整j寻找
        {
            res.push_back(i - j + 2);  // 从1开始计数
            j = next[j];
        }
    }
    return res;
}

int main()
{
    string s, p;
    cin >> s >> p;
    vector<int> ne;
    get_next(ne, p);
    vector<int> results = kmp(s, p, ne);
    for (int result : results)
    {
        cout << result << " " << endl;
    }
    for (int i = 1; i <= p.size(); i++)
    {
        cout << ne[i];
        if (i < p.size()) cout << " ";
    }
    return 0;
}