#include <iostream>
#include <stack>
using namespace std;

class Solution {
    private:
        stack<int> temp;
    public:
        void sortStack(stack<int> &s) {
            while(!s.empty()) {
                int cur = s.top();
                s.pop();
                if(temp.empty() || temp.top() > cur) {
                    temp.push(cur);
                } else {
                    while(!temp.empty() && temp.top() < cur) {
                        s.push(temp.top());
                        temp.pop();
                    }
                    temp.push(cur);
                }
            }
            
            while(!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
        }
};

int main() {
    int N;
    int x;
    cin >> N;
    stack<int> s;
    for(int i = 0; i < N; i++) {
        cin >> x;
        s.push(x);
    }
    Solution sol;
    sol.sortStack(s);
    // 输出
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
