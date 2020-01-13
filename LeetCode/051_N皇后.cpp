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