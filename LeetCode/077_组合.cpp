class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        doCombine(n, k, 1, res, cur);

        return res;
    }

    void doCombine(int n, int k, int start, vector<vector<int>>& res, vector<int>& cur) {
        int curSize = cur.size();

        if(curSize == k) {
            res.push_back(cur);
            return;
        }

        if(k - curSize > n - start + 1) { // 剪枝
            return;
        }

        for(int i = start; i <= n; i++) {
            cur.push_back(i);
            doCombine(n, k, i + 1, res, cur);
            cur.pop_back();
        }
    }
};