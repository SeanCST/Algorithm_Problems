class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n == 0) {
            return 0;
        }
        int total = 0;
        int dp = 0;
        for(int i = 2; i < n; i++) {
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp += 1;
                total += dp;
            } else {
                dp = 0;
            }
        }

        return total;
    }
};