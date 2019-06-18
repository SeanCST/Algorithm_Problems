class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int originalR = nums.size();
        if(originalR == 0)
            return nums;
        int originalC = nums[0].size();
        
        if(originalR * originalC != r * c)
            return nums;
        
        vector<vector<int>> res(r, vector<int>(c, 0));
        int k = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                res[i][j] = nums[k / originalC][k % originalC];
                k++;
            }
        }
        
        return res;
    }
};