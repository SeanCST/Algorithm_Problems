#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Employee {
public:
    int happy;
    vector<Employee> subordinates;
    Employee(int h) : happy(h) {};
    Employee() {};
};

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> happyValues;
    map<int, Employee> m;
    int val;
    for(int i = 0; i < n; i++) {
        cin >> val;
        happyValues.push_back(val);
    }
    Employee boss = Employee(happyValues[0]);
    m[r] = boss;
    int u, v;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        Employee superior = m[u];
        Employee subordinate = Employee(happyValues[i]);
        superior.subordinates.push_back(subordinate);
        m[v] = subordinate;
        m[u] = superior;
    }

    queue<Employee> q;
    q.push(boss);

    while(!q.empty()) {
        Employee e = q.front();
        q.pop();
        cout << e.happy << " : ";
        for(Employee sub : e.subordinates) {
            cout << sub.happy << " , ";
            q.push(sub);
        }
        cout << endl;
    }
    
    return 0;
}