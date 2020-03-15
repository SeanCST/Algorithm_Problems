class Solution {
public:
    void perm(vector<vector<int>>& res, vector<int>& v, map<int, int>& m, int k, int n) {
        if(k == n) {
            res.push_back(v);
            return;
        }

        for(auto& p : m) {
            if(p.second > 0) {
                p.second--;
                v.push_back(p.first);
                perm(res, v, m, k + 1, n);
                p.second++;
                v.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> m;
        for(int x : nums) {
            m[x]++;
        }
        vector<vector<int>> res;
        vector<int> v;

        perm(res, v, m, 0, nums.size());

        return res;
    }
};