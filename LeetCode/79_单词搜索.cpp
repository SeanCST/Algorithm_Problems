class Solution {
private:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m;
    int n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length() == 0) {
            return true;
        }
        if(board.size() == 0 || board[0].size() == 0) {
            return false;
        }

        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(check(board, visited, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool check(vector<vector<char>> board, vector<vector<bool>>& visited, string word, int i, int j, int k) {
        if(k == word.length()) {
            return true;
        }
        if(i < 0 || j < 0 || i >= m || j>= n || board[i][j] != word[k] || visited[i][j]) {
            return false;
        }
        
        visited[i][j] = true;

        for(vector<int> d : directions) {
            if(check(board, visited, word, i + d[0], j + d[1], k + 1)) {
                return true;
            }
        }

        visited[i][j] = false;

        return false;
    }
};