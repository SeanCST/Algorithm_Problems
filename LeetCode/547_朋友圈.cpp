class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        if(N == 0) {
            return 0;
        }
        int num = 0;
        vector<bool> visited(N, false);
        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                dfs(M, i, N, visited);
                num++;
            }
        }

        return num;
    }

    void dfs(vector<vector<int>>& M, int i, int N, vector<bool>& visited) {
        visited[i] = true;
        for(int k = 0; k < N; k++) {
            if(M[i][k] == 1 && !visited[k]) {
                dfs(M, k, N, visited);
            }
        }
    }
};