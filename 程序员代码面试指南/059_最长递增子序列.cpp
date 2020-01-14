#include <iostream>
#include <vector>
using namespace std;

vector<int> generateLIS(vector<int> arr, vector<int> dp) {
    int len = 0;
    int index = 0;
    // dp[i] 表示在以 arr[i] 结尾的情况下，arr[0...i] 中的最大递增子序列长度
    for(int i = 0; i < dp.size(); i++) {
        if(dp[i] > len || (dp[i] == len && arr[i] < arr[index])) {
            len = dp[i];
            index = i;
        }
    }
    vector<int> lis(len, 0);
    lis[--len] = arr[index];
    for(int i = index; i >= 0; i--) {
        if(arr[i] < arr[index] && dp[i] == dp[index] - 1) {
            lis[--len] = arr[i];
            index = i;
        }
    }
    
    return lis;
}

// 时间复杂度 O(n logn)
vector<int> getDp(vector<int> arr) {
    vector<int> dp(arr.size(), 0);
    // 有效区为 ends[0...right]，无效区为 ends[right+1 ... N-1]
    // 对有效区上的位置 b，如果有 ends[b] == c，表示遍历到目前为止，
    // 在所有长度为 b+1 的递增序列中，最小的结尾数是 c
    vector<int> ends(arr.size(), 0); 
    dp[0] = 1;
    ends[0] = arr[0];
    int right = 0;
    int l = 0, r = 0, m = 0;
    for(int i = 1; i < arr.size(); i++) {
        l = 0; 
        r = right;
        while(l <= r) { // 用二分查找找到最左边大于等于 arr[i] 的数，即 ends 中大于等于 arr[i] 的最小的数
            m = (l + r) / 2;
            if(arr[i] > ends[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        right = max(right, l);
        ends[l] = arr[i];
        dp[i] = l + 1;

        for (int j = 0; j <= i; j++)
        {
            cout << ends[j] << " ";
        }
        cout << endl;
    }
    
    return dp;
}

// // 时间复杂度 O(n*n)
// vector<int> getDp(vector<int> arr) {
//     vector<int> dp(arr.size(), 0);
//     for (int i = 0; i < arr.size(); i++) {
//         dp[i] = 1;
//         for (int j = 0; j < i; j++) {
//             if (arr[i] > arr[j]) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//     }
    
//     return dp;
// }

vector<int> getLongestIncreaseSequence(vector<int> arr) {
    if(arr.size() == 0) {
        return arr;
    }
    
    vector<int> dp = getDp(arr);
    return generateLIS(arr, dp);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> res = getLongestIncreaseSequence(arr);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}