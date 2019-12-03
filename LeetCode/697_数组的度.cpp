class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxDegree = 0;
        map<int, int> degrees;
        map<int, int> firstIndex;
        map<int, int> lastIndex;
        for(int i = 0; i < nums.size(); i++) {
            degrees[nums[i]]++;
            maxDegree = max(maxDegree, degrees[nums[i]]);
            lastIndex[nums[i]] = i;
            if(firstIndex.count(nums[i]) == 0) {
                firstIndex[nums[i]] = i;
            }
        }

        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(degrees[nums[i]] == maxDegree) {
                res = min(res, lastIndex[nums[i]] - firstIndex[nums[i]]);
            }
        }

        return res + 1;
    }
};