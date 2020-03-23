class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        // 操作之后，除了重复的那个数字放在了缺失位置上，其他数字都放在了正确的位置上
        // 如：[1,2,3,7,5,6,7,8]
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1) {
                return {nums[i], i + 1};
            }
        }

        return res;
    }
};


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        if(nums.size() <= 1) return res;
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums, i, nums[i] - 1);
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1) {
                res.push_back(nums[i]);
                res.push_back(i + 1);
                return res;
            }
        }

        return res;
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};