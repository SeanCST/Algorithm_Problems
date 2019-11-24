#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    //动态开辟空间
    int **res = new int*[n]; //开辟行
	for(int i = 0; i < n; i++) {
        res[i] = new int[2]; //开辟列
    }

    // 使用单调栈结构解题
    stack<int> monotonicStack;
    for(int i = 0; i < n; i++) {
        while(!monotonicStack.empty() && arr[monotonicStack.top()] > arr[i]) {
            int popIndex = monotonicStack.top();
            monotonicStack.pop();
            res[popIndex][1] = i;
            res[popIndex][0] = monotonicStack.empty() ? -1 : monotonicStack.top();
        }
        monotonicStack.push(i);
    }

    while(!monotonicStack.empty()) {
        int popIndex = monotonicStack.top();
        monotonicStack.pop();
        res[popIndex][0] = monotonicStack.empty() ? -1 : monotonicStack.top();
        res[popIndex][1] = -1;
    }

    for (int i = 0; i < n; i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    //释放开辟的资源
    for(int i = 0; i < n; i++)
		delete[] res[i];
	delete[] res;
}