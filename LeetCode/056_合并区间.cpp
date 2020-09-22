class Solution {
public:
    static bool cmp(vector<int>& interval1, vector<int>& interval2) {
        if(interval1[0] == interval2[0]) {
            return interval1[1] < interval2[1];
        } else {
            return interval1[0] < interval2[0];
        }
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() == 0) {
            return res;
        }

        sort(intervals.begin(), intervals.end(), cmp);

        int curMin = intervals[0][0];
        int curMax = intervals[0][1];
        vector<int> temp(2, 0);

        for(int i = 1; i < intervals.size(); i++) {
            vector<int> interval = intervals[i];
            if(interval[0] > curMax) {
                temp[0] = curMin;
                temp[1] = curMax;
                res.push_back(temp);
                curMin = interval[0];
                curMax = interval[1];
            } else {
                curMax = max(curMax, interval[1]);
            }
        }

        temp[0] = curMin;
        temp[1] = curMax;
        res.push_back(temp);

        return res;
    }
};