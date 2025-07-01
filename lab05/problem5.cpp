#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    string line, token;
    if (!getline(cin, line)) return 0;
    istringstream iss(line);
    // 先把所有标记读入到 vector 中
    vector<string> tokens;
    while (iss >> token) {
        tokens.push_back(token);
    }

    stack<double> st;
    // 逆序遍历 tokens，按前缀（波兰）表达式计算
    for (int i = (int)tokens.size() - 1; i >= 0; --i) {
        token = tokens[i];
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // 前缀：先弹出 a, 再弹出 b
            double a = st.top(); st.pop();
            double b = st.top(); st.pop();
            double res = 0;
            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/") res = a / b;
            st.push(res);
        } else {
            st.push(atof(token.c_str()));
        }
    }

    double result = st.top();
    printf("%f\n", result);
    return 0;
}