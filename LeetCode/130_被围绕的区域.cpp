class Solution {
private:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) {
            return;
        }
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            dfs(board, i, 0, m, n);
            dfs(board, i, n - 1, m, n);
        }
        for(int i = 0; i < n; i++) {
            dfs(board, 0, i, m, n);
            dfs(board, m - 1, i, m, n);
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O'){
            return;
        }
        board[i][j] = '#';
        for(vector<int> d : directions) {
            dfs(board, i + d[0], j + d[1], m, n);
        }
    }
};