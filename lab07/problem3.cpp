#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

template<typename T>
class ScoreManager {
private:
    vector<pair<int, T>> students; // pair<学号, 成绩>

public:
    // 添加学生成绩
    void addStudent(int id, T score) {
        students.push_back(make_pair(id, score));
    }
    
    // 计算平均分
    double getAverage() {
        if (students.empty()) return 0;
        double sum = 0;
        for (const auto& student : students) {
            sum += student.second;
        }
        return sum / students.size();
    }
    
    // 找出前k名学生的学号
    vector<int> getTopK(int k) {
        vector<pair<int, T>> temp = students;
        // 按成绩降序排序，成绩相同按学号升序
        sort(temp.begin(), temp.end(), [](const pair<int, T>& a, const pair<int, T>& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        
        vector<int> result;
        for (int i = 0; i < min(k, (int)temp.size()); i++) {
            result.push_back(temp[i].first);
        }
        return result;
    }
    
    // 统计某个分数段的人数
    int countInRange(T low, T high) {
        int count = 0;
        for (const auto& student : students) {
            if (student.second >= low && student.second <= high) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    char type;
    int n, m;
    cin >> type >> n >> m;
    
    if (type == 'I') {
        ScoreManager<int> manager;
        
        // 读入n个学生成绩
        for (int i = 0; i < n; i++) {
            int score;
            cin >> score;
            manager.addStudent(i + 1, score);
        }
        
        // 处理m个操作
        for (int i = 0; i < m; i++) {
            int op;
            cin >> op;
            
            if (op == 1) {
                int k;
                cin >> k;
                vector<int> topK = manager.getTopK(k);
                for (int j = 0; j < topK.size(); j++) {
                    if (j > 0) cout << " ";
                    cout << topK[j];
                }
                cout << endl;
            } else if (op == 2) {
                int low, high;
                cin >> low >> high;
                cout << manager.countInRange(low, high) << endl;
            }
        }
    } else if (type == 'D') {
        ScoreManager<double> manager;
        
        // 读入n个学生成绩
        for (int i = 0; i < n; i++) {
            double score;
            cin >> score;
            manager.addStudent(i + 1, score);
        }
        
        // 处理m个操作
        for (int i = 0; i < m; i++) {
            int op;
            cin >> op;
            
            if (op == 1) {
                int k;
                cin >> k;
                vector<int> topK = manager.getTopK(k);
                for (int j = 0; j < topK.size(); j++) {
                    if (j > 0) cout << " ";
                    cout << topK[j];
                }
                cout << endl;
            } else if (op == 2) {
                double low, high;
                cin >> low >> high;
                cout << manager.countInRange(low, high) << endl;
            }
        }
    }
    
    return 0;
}
