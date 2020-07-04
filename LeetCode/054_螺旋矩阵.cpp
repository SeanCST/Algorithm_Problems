class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int totalCount = m * n;
        vector<int> res(totalCount, 0);

        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        int k = 0;
        while(top <= bottom && left <= right) {
            // left to right
            for(int i = left; i <= right; i++) {
                res[k++] = matrix[top][i];
            }
            if(k >= totalCount) {
                break;
            }
            top++;

            // top to bottom
            for(int i = top; i <= bottom; i++) {
                res[k++] = matrix[i][right];
            }
            if(k >= totalCount) {
                break;
            }
            right--;

            // right to left
            for(int i = right; i >= left; i--) {
                res[k++] = matrix[bottom][i];
            }
            if(k >= totalCount) {
                break;
            }
            bottom--;

            // bottom to top
            for(int i = bottom; i >= top; i--) {
                res[k++] = matrix[i][left];
            }
            left++;
        }

        return res;
    }
};