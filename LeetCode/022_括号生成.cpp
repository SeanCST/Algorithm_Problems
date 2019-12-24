class Solution {
public:
    // 回溯法
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        
        vector<string> res;
        string curStr;
        curStr += "(";
        generate(res, curStr, n, 1, 0);
        
        return res;
    }
    
    void generate(vector<string>& res, string& curStr, int n, int leftParenthesis, int rightParenthesis) {
        // 不满足括号配对条件直接返回
        if(rightParenthesis > leftParenthesis || leftParenthesis > n)
            return;
        
        if(curStr.length() == n * 2) { // 处理结果
            res.push_back(curStr);
            return;
        }
        
         // 入左括号
        curStr += "(";
        generate(res, curStr, n, leftParenthesis + 1, rightParenthesis);
        curStr.pop_back();

        // 入右括号
        curStr += ")";
        generate(res, curStr, n, leftParenthesis, rightParenthesis + 1);
        curStr.pop_back();
    }
    
    
};