class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end()); // 排序
        for(int i = 0; i < nums.size(); i++) { // i 一轮内固定不动，每一轮移动 j 或 k
            if(i == 0 || nums[i] > nums[i - 1]) {
                int j = i + 1, k = nums.size() - 1;
                while(j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        res.push_back(temp);
                        j++;
                        k--;
                        // 重复时向前移动，直至不重复为止
                        while(j < k && nums[j] == nums[j - 1]) 
                            j++;
                        while(j < k && nums[k] == nums[k + 1])
                            k--;
                    } else if(sum > 0) {
                        k--;
                    } else {
                        j++;
                    }
                }
            }
        }
        return res;
    }
};

                