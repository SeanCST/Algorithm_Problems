class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> res;
        vector<int> cur(n, -1);

        backtrace(res, cur, 0, n);

        vector<vector<string>> ans;
        string s(n, '.');
        for(vector<int> r : res) {
            vector<string> v(n, s);
            for(int i = 0; i < n; i++) {
                v[i][r[i]] = 'Q';
            }
            ans.push_back(v);
        }

        return ans;
    }

    void backtrace(vector<vector<int>>& res, vector<int>& cur, int k, int n) {
        if(k == n) {
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < n; i++) {
            bool conflict = false;
            for(int j = 0; j < k; j++) {
                if(cur[j] == i || abs(cur[j] - i) == abs(j - k)) {
                    conflict = true;
                    break;
                }
            }
            if(!conflict) {
                cur[k] = i;
                backtrace(res, cur, k + 1, n);
            }
        }
    }
};


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> curSolutions;
        vector<int> cur(n, -1);
        solve(0, curSolutions, cur, n);
        
        return transformToStringRes(curSolutions, n);
    }
    
    void solve(int level, vector<vector<int>>& curSolutions, vector<int>& cur, int n) {
        if(level == n) {
            curSolutions.push_back(cur);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            cur[level] = i;

            if (isValid(level, cur)) {
                solve(level + 1, curSolutions, cur, n);
            }
        }
    }
    
    bool isValid(int level, vector<int>& cur) {
        for(int j = 0; j < level; j++) {
            if(cur[j] == cur[level] || abs(cur[j] - cur[level]) == abs(j - level)) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<vector<string>> transformToStringRes(vector<vector<int>> curSolutions, int n) {
        vector<vector<string>> stringResults;
        for(vector<int> numberRes : curSolutions) {
            vector<string> tempStringResult;
            string s(n, '.');
            for(int i : numberRes) {
                s[i] = 'Q';
                tempStringResult.push_back(s);
                s[i] = '.';
            }
            stringResults.push_back(tempStringResult);
        }
        
        return stringResults;
    }
};