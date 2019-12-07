class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        map<int, bool> visited;
        for(int i = 0; i < nums.size(); i++) {
            if(!visited[i]) {
                int count = 0;
                int start = nums[i];
                do {
                    start = nums[start];
                    count++;
                    visited[start] = true;
                } while(start != nums[i]);
                res = max(res, count);
            }
        }

        return res;
    }
};