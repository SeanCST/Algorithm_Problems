class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk; // 单调栈

        for(int i = 0; i < arr.size(); i++) {
            if(!stk.empty() && stk.top() > arr[i]) {
                int curBiggest = stk.top();
                while(!stk.empty() && stk.top() > arr[i]) { 
                    // 把当前单调栈中比 arr[i] 大的数据都 pop 掉
                    stk.pop();
                }
                // 再把当前最大的数给 push 进来，形成新的单调栈
                stk.push(curBiggest);
            } else {
                stk.push(arr[i]);
            }
        }        

        // 最后单调栈中所剩余的各个数，就是把数组划分为最多段，每段中只保留最大的数在单调栈中
        return stk.size();
    }
};
