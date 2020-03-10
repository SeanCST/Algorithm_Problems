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


class Solution {
public:
    bool static cmp(const vector<int>& interval1, const vector<int>& interval2) {
        if(interval1.size() < 2 || interval2.size() < 2) {
            return false;
        }
        return interval1[0] < interval2[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;
        int l = 0, r = 1;
        while(r < intervals.size()) {
            // 判断是否重叠
            if(intervals[l][1] > intervals[r][0]) { // 重叠
                // 移除掉右边界大的那个区间，并把 l 设为右边界小的那个区间的下标，供下一轮比较
                if(intervals[l][1] > intervals[r][1]) {
                    l = r;
                }
                res++;
            } else { // 不重叠
                l = r;
            }

            r++;
        }

        return res;
    }
};