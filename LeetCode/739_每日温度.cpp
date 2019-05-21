class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        
        // 维护一个下标索引栈，当遇到比栈顶索引所对应的值大的时候，就计算差值，并且 pop 栈顶，继续比较
        stack<int> indexs;
        
        for(int i = 0; i < T.size(); i++) {
            while(!indexs.empty() && T[i] > T[indexs.top()]) {
                int preIndex = indexs.top();
                indexs.pop();
                res[preIndex] = i - preIndex;
            }
            indexs.push(i);
        }
        
        return res;
    }
};