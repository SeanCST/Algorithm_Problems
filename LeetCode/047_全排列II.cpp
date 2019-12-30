class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> m;
        for (auto x : nums) {
            ++m[x];
        }
        vector<vector<int> > res;
        vector<int> v;
        doPermuteUnique(0, nums.size(), m, v, res);
        return res;
    }

    void doPermuteUnique(int k, int n, map<int, int>& m, vector<int>& v, vector<vector<int>>& res) {
        if(k == n) {
            res.push_back(v);
            return;
        }

        for(auto& p : m) {
            if(p.second != 0) {
                --p.second;
                v.push_back(p.first);
                doPermuteUnique(k + 1, n, m, v, res);
                ++p.second;
                v.pop_back();
            }
        }
    }
};