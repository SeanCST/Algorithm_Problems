class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int res = INT_MIN, imax = 1, imin = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }

            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            res = max(res, imax);
        }

        return res;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        vector<int> neg(n, 0);
        vector<int> pos(n, 0);

        int res = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                if(i == 0 || pos[i - 1] == 0) {
                    pos[i] = nums[i];
                } else {
                    pos[i] = pos[i - 1] * nums[i];
                }

                if(i > 0 && neg[i - 1] != 0) {
                    neg[i] = neg[i - 1] * nums[i];
                }
            } else if(nums[i] < 0) {
                if(i == 0 || pos[i - 1] == 0) {
                    neg[i] = nums[i];
                } else {
                    neg[i] = pos[i - 1] * nums[i];
                }

                if(i > 0 && neg[i - 1] != 0) {
                    pos[i] = neg[i - 1] * nums[i];
                }
            } 

            res = max(res, pos[i]);
        }

        return res;
    }
};