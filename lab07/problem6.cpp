#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> flights;
    
    // 读入初始航班
    for (int i = 0; i < n; i++) {
        string flight;
        cin >> flight;
        flights.push_back(flight);
    }
    
    int m;
    cin >> m;
    
    // 处理m个操作
    for (int i = 0; i < m; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "ADD") {
            string flight;
            cin >> flight;
            // 直接添加，允许重复
            flights.push_back(flight);
        }
        else if (operation == "DELETE") {
            string flight;
            cin >> flight;
            // 找到并删除指定航班，如果不存在则不操作
            auto it = find(flights.begin(), flights.end(), flight);
            if (it != flights.end()) {
                flights.erase(it);
            }
            // 如果不存在，不需要任何操作
        }
        else if (operation == "CHECK") {
            string flight;
            cin >> flight;
            // 检查航班是否存在
            auto it = find(flights.begin(), flights.end(), flight);
            if (it != flights.end()) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        }
    }
    
    // 输出最终航班数量
    cout << flights.size() << endl;
    
    return 0;
}
