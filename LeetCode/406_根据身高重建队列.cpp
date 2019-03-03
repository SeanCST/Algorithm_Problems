class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;
        
        // 按身高降序，k 值升序排序
        sort(people.begin(), people.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });
        
        // 按排好的序依次插入到结果中
        for(auto p : people) {
            res.insert(res.begin() + p.second, p);
        }
        
        return res;
    }
};