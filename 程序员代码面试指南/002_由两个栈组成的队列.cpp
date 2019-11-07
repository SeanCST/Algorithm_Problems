/* 
题目描述
用两个栈实现队列，支持队列的基本操作。

输入描述:
第一行输入一个整数N，表示对队列进行的操作总数。
下面N行每行输入一个字符串S，表示操作的种类。
如果S为"add"，则后面还有一个整数X表示向队列尾部加入整数X。
如果S为"poll"，则表示弹出队列头部操作。
如果S为"peek"，则表示询问当前队列中头部元素是多少。

输出描述:
对于每一个为"peek"的操作，输出一行表示当前队列中头部元素是多少。

示例1

输入
6
add 1
add 2
add 3
peek
poll
peek

输出
1
2

备注:
1<=N<=1000000
-1000000<=X<=1000000
数据保证没有不合法的操作
*/

#include <iostream>
#include <stack> 

using namespace std;

class Solution {
    private:
        stack<int> stackPush;
        stack<int> stackPop;
        void transferStackPushToStackPop() {
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
    
    public:
        void add(int x) {
            stackPush.push(x);
        }
        
        void poll() {
            if(stackPop.empty()) {
                transferStackPushToStackPop();
            }
            if(!stackPop.empty()) {
                stackPop.pop();
            } else {
                throw out_of_range("");
            }
        }
    
        int peek() {
            if(stackPop.empty()) {
                transferStackPushToStackPop();
            }
            if(!stackPop.empty()) {
                return stackPop.top();
            } else {
                throw out_of_range("");
            }
        }
};

int main() {
    int N, x;
    cin >> N;
    string str;
    Solution s;
    while(N--) {
        cin >> str;
        if(str == "add") {
            cin >> x;
            s.add(x);
        } else if(str == "peek") {
            cout << s.peek() << endl;
        } else if(str == "poll") {
            s.poll();
        }
    }
    
    return 0;
}