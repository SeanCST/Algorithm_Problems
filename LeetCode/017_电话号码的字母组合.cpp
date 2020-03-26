class Solution {
map<char, string> m = {{'2' , "abc"}, {'3' , "def"}, {'4' , "ghi"}, 
                       {'5' , "jkl"}, {'6' , "mno"}, {'7' , "pqrs"}, 
                       {'8' , "tuv"}, {'9' , "wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0) {
            return res;
        }
        process(digits, res, "");

        return res;
    }

    void process(string& digits, vector<string>& res, string curStr) {
        int k = curStr.length();
        if(k == digits.length()) {
            res.push_back(curStr);
            return;
        }

        string s = m[digits[k]];
        for(char c : s) {
            process(digits, res, curStr + c);
        }
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) {
            return res;
        }
        
        unordered_map<char, string> table{
            {'0', " "}, {'1', "*"}, {'2', "abc"},
            {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, 
            {'9', "wxyz"}
        };
        func(res, "", digits, table, 0);

        return res;
    }

    // 回溯法
    void func(vector<string>& res, string str, string digits, unordered_map<char, string>& m, int k) {
        if (str.length() == digits.length()) { // 字符串长度与 digits 长度相等作为终止递归的判定条件
            res.push_back(str);
            return;
        }
        
        string tmp = m[digits[k]];
        for(char w : tmp) {
            str += w;
            func(res, str, digits, m, k + 1);
            str.pop_back();
        }
        
        return;
    }

};