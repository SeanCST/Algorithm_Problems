class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxLength = 0;
        map<int, int> m;
        // 用哈希表 m 对数组中所有元素进行计数
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        
        map<int, int>::iterator iter = m.begin();
        
        // 遍历哈希表，看各元素与其相邻的元素数目之和最大的数目
        while(iter != m.end()) {
            int key = iter->first;
            if(m[key - 1] > 0) {
                maxLength = max(maxLength, abs(iter->second + m[key - 1]));
            }
            iter++;
        }
        
        return maxLength;
    }
};