class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> res(n, false);

        int mostCandy = 0;
        for(int candy : candies) {
            mostCandy = max(mostCandy, candy);
        }

        for(int i = 0; i < n; i++) {
            if(candies[i] + extraCandies >= mostCandy) {
                res[i] = true;
            }
        }

        return res;
    }
};