class Solution {
public:
    string convert(string s, int numRows) {
        int k = 0;
        vector<vector<char>> vec(numRows);
        while(k < s.length()) {
            for(int i = 0; i < numRows; i++) {
                if(k < s.length())
                    vec[i].push_back(s[k++]);
                else
                    break;
            }
            for(int i = numRows - 2; i > 0; i--) {
                if(k < s.length())
                    vec[i].push_back(s[k++]);
                else
                    break;
            }
        }
        
        string res;
        for(int i = 0; i < vec.size(); i++) {
            for(int j = 0; j < vec[i].size(); j++) {
                res += vec[i][j];
            }
        }
        
        return res;
    }
};