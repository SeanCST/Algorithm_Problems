class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curLine(rowIndex + 1, 1);

        for(int i = 1; i <= rowIndex; i++)
        {
            int temp = curLine[0];
            for(int j = 1; j < i; j++)
            {
                int temp1 = curLine[j];
                curLine[j] = temp + curLine[j];
                temp = temp1;
            }
        }
        
        return curLine;
    }
};