class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        int up = 1, down = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                up = down + 1;
            } else if(nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }

        return max(up, down);
    }
};

// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         if(n <= 1) {
//             return n;
//         }
//         vector<int> up(n, 1);
//         vector<int> down(n, 1);
//         for(int i = 1; i < n; i++) {
//             if(nums[i] > nums[i - 1]) {
//                 up[i] = down[i - 1] + 1;
//                 down[i] = down[i - 1];
//             } else if(nums[i] < nums[i - 1]) {
//                 down[i] = up[i - 1] + 1;
//                 up[i] = up[i - 1];
//             } else {
//                 down[i] = down[i - 1];
//                 up[i] = up[i - 1];
//             }
//         }

//         return max(up[n - 1], down[n - 1]);
//     }
// };