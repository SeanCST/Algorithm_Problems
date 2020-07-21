class Solution {
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> meetings;
        for(vector<int> interval : intervals) {
            meetings.push_back(pair<int, int>(interval[0], 1)); // 上车
            meetings.push_back(pair<int, int>(interval[1], -1)); // 下车
        }
        sort(meetings.begin(), meetings.end(), cmp);

        int maxCount = 0;
        int count = 0;
        for(pair<int, int> meeting : meetings) {
            count += meeting.second;
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};