class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {       
        unordered_map<string, vector<string>> m;
        return helper(s, wordDict, m);
    }

    vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& m) {
        if(m.find(s) != m.end()) {
            return m[s];
        }
        if(s.length() == 0) {
            return {""};
        }

        vector<string> res;
        for(string word : wordDict) {
            if(word != s.substr(0, word.size())) {
                continue;
            }
            vector<string> tmp = helper(s.substr(word.size()), wordDict, m);
            for(string item : tmp) {
                res.push_back(word + (item.length() == 0 ? "" : " " + item));
            }
        }
        m[s] = res;

        return res;
    }
};