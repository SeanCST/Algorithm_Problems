class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        doCombination(1, k, n, res, cur);

        return res;
    }

    void doCombination(int start, int k, int n, vector<vector<int>>& res, vector<int>& cur) {
        if(k == 0 && n == 0) {
            res.push_back(cur);
            return;
        }
        if(k == 0 || n == 0) {
            return;
        }

        for(int i = start; i <= 9; i++) {
            if(i > n) {
                break;
            }
            cur.push_back(i);
            doCombination(i + 1, k - 1, n - i, res, cur);
            cur.pop_back();
        }
    }
};