class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int delta = INT_MAX;
        int res;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] != nums[i-1]) {
                int l = i + 1, r = nums.size() - 1;
                while(l < r) {
                    int s = nums[i] + nums[l] + nums[r];
                    if(s == target) {
                        return s;
                    } else if(s > target) {
                        if(s - target < delta) {
                            delta = s - target;
                            res = s;
                        }
                        r--;
                    } else {
                        if(target - s < delta) {
                            delta = target - s;
                            res = s;
                        }                        
                        l++;
                    }
                }
            }
        }
        
        return res;
    }
};