#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Employee {
    int happy;
    vector<Employee *> subordinates;
    Employee(int h) : happy(h) {};
};

struct ReturnType {
    int yesHeadMax;
    int noHeadMax;
    ReturnType(int yHM, int nHM) : yesHeadMax(yHM), noHeadMax(nHM) {};
};

ReturnType* process(Employee *X) {
    int yesX = X->happy;
    int noX = 0;
    
    if(X->subordinates.empty()) { // 基层员工
        ReturnType *r = new ReturnType(yesX, noX);
        return r;
    } else {
        for (Employee *sub : X->subordinates) {
            ReturnType *subdData = process(sub);
            yesX += subdData->noHeadMax;
            noX += max(subdData->yesHeadMax, subdData->noHeadMax);
        }
        ReturnType *r = new ReturnType(yesX, noX);
        return r;
    }
}

int getMaxHappy(Employee *boss) {
    if(!boss) {
        return 0;
    }
    ReturnType *data = process(boss);
    return max(data->yesHeadMax, data->noHeadMax);
}

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> happyValues;
    map<int, Employee *> m;
    int val;
    for(int i = 0; i < n; i++) {
        cin >> val;
        happyValues.push_back(val);
    }
    Employee *boss = new Employee(happyValues[0]);
    m[r] = boss;
    int u, v;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        Employee *superior = m[u];
        Employee *subordinate = new Employee(happyValues[i]);
        superior->subordinates.push_back(subordinate);
        m[v] = subordinate;
    }

    cout << getMaxHappy(boss);

    return 0;
}
