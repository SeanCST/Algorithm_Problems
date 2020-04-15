// 贪心
class Solution {
public:
    bool static cmp(const vector<int>& pair1, const vector<int>& pair2) {
        return pair1[1] < pair2[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int res = 1;
        int tmp = pairs[0][1];
        for(int i = 1; i < pairs.size(); i++) {
            if(pairs[i][0] > tmp) {
                res++;
                tmp = pairs[i][1];
            }
        }

        return res;
    }
};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> dp(pairs.size(), 1);
        for(int i = 1; i < pairs.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[pairs.size() - 1];
    }
};