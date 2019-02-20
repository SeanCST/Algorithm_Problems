class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j <= i + k && j < nums.size(); j++) {
                if(nums[i] == nums[j])
                    return true;
            }
        }
        
        return false;
    }
};


// 时间换空间
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;

        for(int i = 0; i < nums.size(); i++) {
            if(m.find(nums[i]) != m.end()) { // 之前已经出现过
                if(i - m[nums[i]] <= k)
                    return true;
            }
            m[nums[i]] = i;
        }
        
        return false;
    }
};


