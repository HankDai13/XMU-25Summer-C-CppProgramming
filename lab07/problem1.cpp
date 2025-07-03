#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class MyPoint {
public:
    double x, y;
    
    MyPoint() : x(0), y(0) {}
    MyPoint(double x, double y) : x(x), y(y) {}
    
    // 重载>>运算符，实现坐标输入
    friend istream& operator>>(istream& in, MyPoint& point) {
        in >> point.x >> point.y;
        return in;
    }
};

// 计算两点间距离的函数
double Dist(const MyPoint& p1, const MyPoint& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        MyPoint p1, p2;
        cin >> p1 >> p2;
        
        double distance = Dist(p1, p2);
        cout << fixed << setprecision(2) << distance << endl;
    }
    
    return 0;
}
