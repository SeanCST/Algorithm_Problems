/*
题目描述
汉诺塔问题比较经典，这里修改一下游戏规则：现在限制不能从最左侧的塔直接移动到最右侧，也不能从最右侧直接移动到最左侧，而是必须经过中间。求当塔有n层的时候，打印最优移动过程和最优移动总步数。

输入描述:
输入一个数n，表示塔层数

输出描述:
按样例格式输出最优移动过程和最优移动总步数

输入
2

输出
Move 1 from left to mid
Move 1 from mid to right
Move 2 from left to mid
Move 1 from right to mid
Move 1 from mid to left
Move 2 from mid to right
Move 1 from left to mid
Move 1 from mid to right
It will move 8 steps.

当塔数为两层时，最上层的塔记为1，最下层的塔记为2
备注: 1 ≤ n ≤ 12
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 递归解法

// void move(int index, string from, string to) {
//     cout << "Move " << index << " from " << from << " to " << to << endl;
// }

// int hanoi(int n, string from, string to) {
//     if(n == 1) {
//         move(1, from, "mid");
//         move(1, "mid", to);
//         return 2;
//     }

//     int count1 = hanoi(n - 1, from, to);
//     move(n, from, "mid");
//     int count2 = hanoi(n - 1, to, from);
//     move(n, "mid", to);
//     int count3 = hanoi(n - 1, from, to);

//     return count1 + count2 + count3 + 2;
// }

// int main() {
//     int n;
//     cin >> n;    
//     int steps = hanoi(n, "left", "right");
//     cout << "It will move " << steps << " steps.";
//     return 0;
// }


// 非递归解法 ： 3 个栈

enum Action {
    NoAction, LToM, MToL, MToR, RToM
};

int fStackTotSatck(Action &lastAction, Action preNoAction, Action nowAction, stack<int>& fromStack, stack<int>& toStack, string from, string to) {
    if(lastAction != preNoAction && fromStack.top() < toStack.top()) {
        toStack.push(fromStack.top());
        fromStack.pop();
        cout << "Move " << toStack.top() << " from " << from << " to " << to << endl;
        lastAction = nowAction;
        return 1;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;    

    stack<int> left, mid, right;
    left.push(INT_MAX);
    mid.push(INT_MAX);
    right.push(INT_MAX);
    for (int i = n; i > 0; i--) {
        left.push(i);
    }
    
    // 四个动作选项，每次只有一个动作达标
    int steps = 0;
    Action lastAction = NoAction;
    while (right.size() != n + 1) {
        steps += fStackTotSatck(lastAction, MToL, LToM, left, mid, "left", "mid");
        steps += fStackTotSatck(lastAction, LToM, MToL, mid, left, "mid", "left");
        steps += fStackTotSatck(lastAction, RToM, MToR, mid, right, "mid", "right");
        steps += fStackTotSatck(lastAction, MToR, RToM, right, mid, "right", "mid");
    }

    cout << "It will move " << steps << " steps.";
    return 0;
}