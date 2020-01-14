#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 递归
// int process(vector<int> arr, int i, int from, int mid, int to) {
//     if(i == -1) {
//         return 0;
//     }
//     if(arr[i] != from && arr[i] != to) {
//         return -1;
//     }

//     if (arr[i] == from) {
//         return process(arr, i - 1, from, to, mid);
//     } else {
//         int rest = process(arr, i - 1, mid, from, to);
//         if (rest == -1) {
//             return -1;
//         }
//         return (1 << i) + rest;
//     }
// }

// int getStep(vector<int> arr) {
//     if(arr.size() == 0) {
//         return -1;
//     }
//     return process(arr, arr.size() - 1, 1, 2, 3);
// }

// 非递归
int getStep(vector<int> arr) {
    if(arr.size() == 0) {
        return -1;
    }
    int from = 1, mid = 2, to = 3;
    int i = arr.size() - 1;
    int res = 0;
    int temp = 0;
    while (i >= 0) {
        if(arr[i] != from && arr[i] != to) {
            return -1;
        }
        if (arr[i] == to) {
            res += (1 << i);
            temp = from;
            from = mid;
        } else {
            temp = to;
            to = mid;
        }
        mid = temp;
        i--;
    }
    return res;
}

// void func(int n, string from, string mid, string to) {
//     if (n == 1) {
//         cout << "move from " << from << " to " << to << endl;
//     } else {
//         func(n - 1, from, to, mid);
//         func(1, from, mid, to);
//         func(n - 1, mid, from, to);
//     }
// }

// void hanoi(int n) {
//     if (n > 0) {
//         func(n, "left", "mid", "right");
//     }
// }

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // hanoi(n);

    cout << getStep(arr);
    
    return 0;
}
    