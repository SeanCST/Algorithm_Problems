class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();

        for(int k = n - 1; k >= 1; k--) {
            // nums[j...n-1] 递减, nums[i] < nums[j]
            if(nums[k - 1] < nums[k]) {
                i = k - 1;
                j = k;
                break;
            }
        }

        if(i >= 0) {
            for(int k = n - 1; k >= i; k--) {
                // 从右往左找到第一个比 nums[i] 大的数
                if(nums[k] > nums[i]){
                    swap(nums[i], nums[k]);
                    break;
                }
            }
        }

        int left = j, right = n - 1;
        while(left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
};
