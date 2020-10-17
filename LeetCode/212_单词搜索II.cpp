class TrieNode {
public:
    string word = "";
    vector<TrieNode* > nodes;
    TrieNode(): nodes(26, 0) {}
};

class Solution {
    vector<string> res;
    int R, C;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size() == 0 || board[0].size() == 0) {
            return res;
        }
        R = board.size();
        C = board[0].size();

        // build Trie Tree
        TrieNode *root = new TrieNode();
        for(string w : words) {
            TrieNode *cur = root;
            for(int i = 0; i < w.length(); i++) {
                int index = w[i] - 'a';
                if(cur->nodes[index] == 0) {
                    cur->nodes[index] = new TrieNode();
                }
                cur = cur->nodes[index];
            }
            cur->word = w;
        }

        // dfs
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                dfs(board, root, i, j);
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& board, TrieNode *root, int i, int j) {
        char c = board[i][j];
        if(c == '.' || root->nodes[c - 'a'] == 0) {
            return;
        }
        root = root->nodes[c - 'a'];

        if(root->word != "") {
            res.push_back(root->word);
            root->word = "";
        }

        board[i][j] = '.';
        if(i > 0) {
            dfs(board, root, i - 1, j);
        }
        if(i < R - 1) {
            dfs(board, root, i + 1, j);
        }
        if(j > 0) {
            dfs(board, root, i, j - 1);
        }
        if(j < C - 1) {
            dfs(board, root, i, j + 1);
        }

        board[i][j] = c;
    }
};

// class Solution {
// public:
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         vector<string> res;
//         if(board.size() == 0 || board[0].size() == 0) {
//             return res;
//         }
//         int R = board.size();
//         int C = board[0].size();

//         vector<vector<bool>> visited;
//         for(string word : words) {
//             bool found = false;
//             for(int i = 0; i < R; i++) {
//                 for(int j = 0; j < C; j++) {
//                     visited.resize(R, vector<bool>(C, false));
//                     found = find(board, visited, word, 0, R, C, i, j);
//                     if(found) {
//                         res.push_back(word);
//                         break;
//                     }
//                 }
//                 if(found) {
//                     break;
//                 }       
//             }
//         }

//         return res;
//     }

//     bool find(vector<vector<char>>& board, 
//               vector<vector<bool>>& visited,
//               string word,
//               int k,
//               int R,
//               int C,
//               int i,
//               int j) {
//         if(k == word.length()) {
//             return true;
//         }
//         if(i < 0 || j < 0 || i >= R || j >= C || visited[i][j] == true || board[i][j] != word[k]) {
//             return false;
//         }
//         visited[i][j] = true;
//         k++;
        
//         bool res = find(board, visited, word, k, R, C, i + 1, j) ||
//                    find(board, visited, word, k, R, C, i - 1, j) ||
//                    find(board, visited, word, k, R, C, i, j + 1) ||
//                    find(board, visited, word, k, R, C, i, j - 1);

//         visited[i][j] = false;

//         return res;
//     }
// };