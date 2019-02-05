class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows <= 0) {
            return res;
        }
        vector<int> lastLine(1, 1); // 第一行为 1 个数，值为 1
        res.push_back(lastLine);
        for(int i = 2; i <= numRows; i++)
        {
            vector<int> curLine(i); // 当前行有 i 个数
            curLine[0] = 1;
            curLine[i - 1] = 1;
            for(int j = 1; j < i - 1; j++)
            {
                curLine[j] = lastLine[j - 1] + lastLine[j];
            }
            res.push_back(curLine);
            lastLine = curLine;
        }
        
        return res;
    }
};