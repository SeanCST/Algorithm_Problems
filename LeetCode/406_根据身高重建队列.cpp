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

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return (a[0] > b[0]) || (a[0] == b[0] && a[1] < b[1]);
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        // 按照身高 h 降序排序，对于同身高的人按照 k 升序排序
        sort(people.begin(), people.end(), cmp);

        // 以这样的顺序插入，对于不同的身高，保证后插入的身高矮于先插入的，不会造成先插入的那些序号出问题
        // 对于相同的身高，后插入的序号比先插入的要大，不会造成后插入的插到前面造成先插入的序号出问题
        
        for(auto p : people) {
            res.insert(res.begin() + p[1], p);
        }

        return res;
    }
};