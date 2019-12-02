class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n, 0);
        res[0] = 1;
        for(int i = 1, interval = k; i <= k; i++, interval--) {
            res[i] = i % 2 == 1 ? res[i - 1] + interval : res[i - 1] - interval;
        }
        for(int i = k + 1; i < n; i++) {
            res[i] = i + 1;
        }

        return res;
    }
};