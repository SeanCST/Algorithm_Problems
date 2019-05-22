class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        
        stack<int> pre;
        for(int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];
            while(!pre.empty() && num > nums[pre.top()]) {
                res[pre.top()] = num;
                pre.pop();
            }
            if(i < n) {
                pre.push(i);
            }
        }
        
        return res;
    }
};