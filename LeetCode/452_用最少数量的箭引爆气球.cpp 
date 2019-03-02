class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
    
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.empty()) return 0;
        
        sort(points.begin(), points.end(), cmp);
        
        int end = points[0].second, res = 1;
        for(int i = 1; i < points.size(); i++) {
            if(points[i].first > end) {
                res++;
                end = points[i].second;
            }
        }
        
        return res;
    }
};