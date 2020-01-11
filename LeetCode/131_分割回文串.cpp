class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;

        doPartition(0, res, cur, s);

        return res;
    }

    void doPartition(int start, vector<vector<string>>& res, vector<string>& cur, string s) {
        int len = s.length();
        if(start == len) {
            res.push_back(cur);
            return;
        }

        for(int i = start; i < len; i++) {
            if(isPalindrome(s, start, i)) {
                cur.push_back(s.substr(start, i - start + 1));
                doPartition(i + 1, res, cur, s);
                cur.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int begin, int end) {
        while(begin < end) {
            if(s[begin] != s[end]) {
                return false;
            }
            begin++;
            end--;
        }

        return true;
    }
};