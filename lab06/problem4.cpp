#include <iostream>
#include <vector>
using namespace std;


int n;
vector<int> path;
void listNums(int u)
{
    if (u > n)
    {
        for (int num : path)
        {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    path.push_back(u);
    listNums(u + 1);
    path.pop_back();
    listNums(u + 1);
}
int main()
{
    cin >> n;
    listNums(1);
}