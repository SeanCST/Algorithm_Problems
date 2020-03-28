class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;

        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);

        doSubsetsWithDup(0, visited, res, cur, nums);

        return res;
    }

    void doSubsetsWithDup(int start, vector<bool>& visited, vector<vector<int>>& res, vector<int>& cur, vector<int> nums) {
        res.push_back(cur);

        for(int i = start; i < nums.size(); i++) {
            // 若前一个相同的还未加入，就加入当前这个，会造成重复
            if(i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            cur.push_back(nums[i]);
            visited[i] = true;
            doSubsetsWithDup(i + 1, visited, res, cur, nums);
            visited[i] = false;
            cur.pop_back();
        }
    }
};