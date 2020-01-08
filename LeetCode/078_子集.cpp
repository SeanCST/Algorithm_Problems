class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        doSubsets(0, res, cur, nums);

        return res;
    }

    void doSubsets(int start, vector<vector<int>>& res, vector<int>& cur, vector<int> nums) {
        res.push_back(cur);
        if(start >= nums.size()) {
            return;
        }
        for(int i = start; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            doSubsets(i + 1, res, cur, nums);
            cur.pop_back();
        }
    }
};