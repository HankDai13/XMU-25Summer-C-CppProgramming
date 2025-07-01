#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int>& memo) {
    if (n <= 2) return 1;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib(n-1, memo) + fib(n-2, memo);
}

int main()
{
    int n;
    cin >> n;
    vector<int> memo(n + 1, -1); 
    cout << fib(n, memo) << endl;
    return 0;
}