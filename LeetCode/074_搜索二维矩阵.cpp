class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        // 两次调用二分查找，第一次定位到某一行，第二次在已定位的行中确定是否存在要找数

        int up = 0, down = m - 1;
        while(up < down) {
            int mid = up + (down - up) / 2;
            if(matrix[mid][n - 1] == target) {
                return true;
            } else if (matrix[mid][n - 1] > target) {
                down = mid;
            } else {
                up = mid + 1;
            }
        }

        int foundRow = up;

        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[foundRow][mid] == target) {
                return true;
            } else if (matrix[foundRow][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};