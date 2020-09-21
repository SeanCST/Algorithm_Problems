class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, cur = 0;
        int p2 = nums.size() - 1;

        while(cur <= p2) {
            if(nums[cur] == 0) {
                swap(nums[p0++], nums[cur++]);
            } else if(nums[cur] == 2) {
                swap(nums[cur], nums[p2--]);
            } else {
                cur++;
            }
        }
    }
};