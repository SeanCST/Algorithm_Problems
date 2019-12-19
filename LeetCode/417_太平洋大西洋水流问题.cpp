class Solution {
private:
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int m;
    int n;
    vector<vector<int>> mtx;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if(matrix.size() == 0) {
            return res;
        }
        m = matrix.size();
        n = matrix[0].size();
        mtx = vector<vector<int>>(matrix);
        vector<vector<bool>> canReachP(m, vector<bool>(n, false));
        vector<vector<bool>> canReachA(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            dfs(i, 0, canReachP);
            dfs(i, n - 1, canReachA);
        }

        for(int i = 0; i < n; i++) {
            dfs(0, i, canReachP);
            dfs(m - 1, i, canReachA);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(canReachA[i][j] && canReachP[i][j]) {
                    vector<int> r = {i, j};
                    res.push_back(r);
                }
            }
        }

        return res;
    }

    void dfs(int r, int c, vector<vector<bool>>& canReach) {
        if(canReach[r][c]) {
            return;
        }
        canReach[r][c] = true;
        for(vector<int> d : directions) {
            int nextR = r + d[0];
            int nextC = c + d[1];
            if(nextR < 0 || nextR >= m || nextC < 0 || nextC >= n || mtx[nextR][nextC] < mtx[r][c]) {
                continue;
            }
            dfs(nextR, nextC, canReach);
        }
    }
};