class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) {
            return {0};
        }
        if(n == 1) {
            return {0, 1};
        }

        vector<int> res;
        vector<int> lastRes = grayCode(n - 1);

        int base = 0;
        for(int i = 0; i < lastRes.size(); i++) {
            res.push_back(base | lastRes[i]);
        }
        base = 1 << n - 1;
        for(int i = lastRes.size() - 1; i >= 0 ; i--) {
            res.push_back(base | lastRes[i]);
        }

        return res;
    }
};


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1<<n, 0);
        for(int i = 0; i < 1<<n; i++) {
            res[i] = i ^ i>>1;
        }

        return res;
    }
};