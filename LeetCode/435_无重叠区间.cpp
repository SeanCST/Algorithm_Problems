/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(const Interval& a, const Interval& b) {
         return a.end < b.end;
    }
    
    int eraseOverlapIntervals(vector<Interval>& intervals) {  
        if(intervals.size() == 0)
            return 0;
        
        // 先按右边界从小到大给各区间排序
        sort(intervals.begin(), intervals.end(), cmp);
        
        // 计算能不重叠的最大区间数
        int end = intervals[0].end, count = 1;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start >= end) {
                count++;
                end = intervals[i].end;
            }
        }
        
        return intervals.size() - count;
    }
    

};