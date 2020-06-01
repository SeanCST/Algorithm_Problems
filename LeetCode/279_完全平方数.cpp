class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                if(dp[i] == 0) {
                    dp[i] = dp[i - j * j] + 1;
                } else {
                    dp[i] = min(dp[i - j * j] + 1, dp[i]);
                }
            }
        }

        return dp[n];
    }
};

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            dp[i] = i; // 最坏的情况就是全部由 1 组成 
            for(int j = 1; i - j * j >= 0; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

class Solution {
public:
    int numSquares(int n) {
         queue<pair<int,int>> q;
        
        q.push(make_pair(n,0)); // n 是给定的正整数，0 是初始步数

        vector<bool> visited(n + 1, false); // 层序遍历减枝，图可能会反复遍历相同的节点。这里之前遍历过的，后面就不用遍历计算了。
        visited[n] = true;
        
        while(!q.empty()) {
            
            int num = q.front().first;
            int step = q.front().second;
            
            q.pop();
            
            for(int i = 1; num - i * i >= 0; i++) {
                int a = num - i * i;  // 减去平方数，获得下一个图节点位置，即是 step + 1 层。可能有多种情况，会到达多个节点。
                if(a == 0)
                    return step + 1;  // 当到达 0 节点，说明已经走完了。由于是层序的，第一个到达 0 节点就直接返回步数了。
                if(!visited[a]){
                    q.push(make_pair(a, step + 1));  // 记录到达当前节点，已经走了的步数。
                    visited[a] =true;
                }
            }
        }
        
        return 0;
    }
};