class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // 单调栈
        stack<int> stk;

        for(int i = 0; i < arr.size(); i++) {
            if(!stk.empty() && stk.top() > arr[i]) {
                int head = stk.top();
                while(!stk.empty() && stk.top() > arr[i]) {
                    stk.pop();
                }
                stk.push(head);
            } else {
                stk.push(arr[i]);
            }
        }

        return stk.size();
    }
};