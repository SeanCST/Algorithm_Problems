class Solution {
public:
    void backtrack(int n, vector<int> &nums, vector<vector<int>> &res, int first)
    {
        if(first == n) {
            res.push_back(nums);
        }

        for(int i = first; i < n; i++) {
            swap(nums[first], nums[i]);
            backtrack(n, nums, res,  first + 1);
            swap(nums[first], nums[i]);
        }
    }

    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(nums.size(), nums, res, 0);
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> cur;
//         vector<bool> visited(nums.size(), false);
        
//         doPermute(nums, res, cur, visited);

//         return res;
//     }

//     void doPermute(vector<int> nums, vector<vector<int>>& res, vector<int>& cur, vector<bool>& visited) {
//         if(cur.size() == nums.size()) {
//             res.push_back(cur);
//             return;
//         }

//         for(int i = 0; i < nums.size(); i++) {
//             if(!visited[i]) {
//                 visited[i] = true;
//                 cur.push_back(nums[i]);
//                 doPermute(nums, res, cur, visited);
//                 cur.pop_back();
//                 visited[i] = false;
//             }
//         }
//     }
// };