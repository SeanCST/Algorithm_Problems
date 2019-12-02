/*
题目描述
一个不含有负数的数组可以代表一圈环形山，每个位置的值代表山的高度。比如，{3,1,2,4,5}，{4,5,3,1,2}或{1,2,4,5,3}都代表同样结构的环形山。3->1->2->4->5->3 方向叫作 next 方向(逆时针)，3->5->4->2->1->3 方向叫作 last 方向(顺时针)。
山峰 A 和 山峰 B 能够相互看见的条件为:
1. 如果 A 和 B 是同一座山，认为不能相互看见。
2. 如果 A 和 B 是不同的山，并且在环中相邻，认为可以相互看见。
3. 如果 A 和 B 是不同的山，并且在环中不相邻，假设两座山高度的最小值为 min。如果 A 通过 next 方向到 B 的途中没有高度比 min 大的山峰，或者 A 通过 last 方向到 B 的途中没有高度比 min 大的山峰，认为 A 和 B 可以相互看见。
问题如下：
给定一个不含有负数且没有重复值的数组 arr，请问有多少对山峰能够相互看见？

输入描述:
第一行一个整数 T，表示测试数据的组数。
每组数据的第一行有三个数字 n, p, m，其中 n 表示 山峰的数量，
山峰的高度数组等于 1 - p 的 p! 个全排列按字典序排序后的第 m 个全排列的前 n 项。

输出描述:
输出一行一个整数表示答案。

示例1

输入
1
5 5 2

输出
7

说明
1-5 的全排列排序后的第二个排列 为 1 2 3 5 4

备注:
1 ≤ T ≤ 10000
1 ≤ n ≤ p ≤ 1000000
1 ≤ m ≤ p!
*/

// 简单版：数字各不相同
// #include <iostream>
// using namespace std;

// int main() {
//     int T, n, p, m;
//     cin >> T;
//     while(T--) {
//         cin >> n >> p >> m;
//         // 山峰的高度数组等于 1 - p 的 p! 个全排列按字典序排序后的第 m 个全排列的前 n 项
//         // 在每座山峰高度均不相同的情况下，除了最高峰和次高峰，其他每座山峰在两个方向上分别遇到第一座比它高的山峰，即为 (n - 2) * 2 对
//         // 最高峰和次高峰之间为一对
//         cout << max((n - 2) * 2 + 1, 0) << endl;
//     }
    
//     return 0;
// }


// 复杂版：数字可能相同
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Record {
public:
    int value;
    int times;
    
    Record(int val) {
        value = val;
        times = 1;
    }
};

// 同样的数字相互之间的对数
int getInternalSum(int k) {
    return k == 1 ? 0 : (k * (k - 1) / 2);
}

int getVisibleNum(vector<int> nums) {
    int n = nums.size();
    if(n <= 1) return 0;
    // 先找出其中一个最大值的位置
    int maxIndex = 0;
    for(int i = 1; i < n; i++) {
        if(nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
    }
    
    stack<Record> stk;
    stk.push(Record(nums[maxIndex]));
    int res = 0;
    int currentIndex = (maxIndex + 1) % n;
    while(currentIndex != maxIndex) {
        while(stk.top().value < nums[currentIndex]) { // 栈顶元素值小于当前元素
            int k = stk.top().times;
            stk.pop();
            res += 2 * k + getInternalSum(k);
        }
        
        if (stk.top().value == nums[currentIndex]) { // 栈顶元素值等于当前元素
            Record top = stk.top();
            stk.pop();
            top.times++;
            stk.push(top);
        } else { // 栈顶元素值大于当前元素
            stk.push(Record(nums[currentIndex]));
        }
        
        currentIndex = (currentIndex + 1) % n;
    }
    
    // 已经遍历完了一圈，现在对栈中剩余的元素进行处理
    while(stk.size() > 2) { // 第一阶段，栈中剩余元素大于 2 个
        int times = stk.top().times;
        res += 2 * times + getInternalSum(times);
        stk.pop();
    }
    
    if(stk.size() == 2) { // 第二阶段，栈中剩余元素等于 2 个
        int times = stk.top().times;
        res += getInternalSum(times);
        stk.pop();
        res += stk.top().times == 1 ? times : 2 * times;
    }
    
    if(stk.size() == 1) { // 第三阶段，栈中剩余元素只剩 1 个
        res += getInternalSum(stk.top().times);
    }
    
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int x;
    while(n--) {
        cin >> x;
        nums.push_back(x);
    }
    
    cout << getVisibleNum(nums);
    
    return 0;
}
