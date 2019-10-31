/* 
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。

示例:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
说明:
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        int low = matrix[0][0], high = matrix[m - 1][n - 1];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n && matrix[i][j] <= mid; j++) {
                    cnt++;
                }
            }
            if(cnt < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        //升序队列
        //priority_queue <int,vector<int>,greater<int> > q;
        //降序队列
        //priority_queue <int,vector<int>,less<int> >q;
        //c++默认是降序队列，即大顶堆
        priority_queue<int> q;
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(q.size() < k) {
                    q.push(matrix[i][j]);
                } else {
                    if(matrix[i][j] < q.top()) {
                        q.pop();
                        q.push(matrix[i][j]);
                    }
                }
            }
        }
        return q.top();
    }
};