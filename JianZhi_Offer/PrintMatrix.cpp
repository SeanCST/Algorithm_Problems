/* 剑指 Offer - 顺时针打印矩阵

 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 **/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int rows = matrix.size(); // 行数
        vector<int> firstRow = matrix[0];
        int cols = firstRow.size(); // 列数
         
        vector<int> res; // 存放元素的结果
         
        int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
        while(top <= bottom && left <= right) {
            // 从左到右
            for(int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
 
            // 从上到下
            for(int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
 
            // 从右到左，避免只有一行重复打印
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
 
            // 从下到上，避免只有一列重复打印
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
 
        return res;
    }
};