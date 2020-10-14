class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> h;
        multiset<int> m;

        for(vector<int> b : buildings) {
            h.push_back({b[0], -b[2]});
            h.push_back({b[1], b[2]});
        }        

        sort(h.begin(), h.end());

        m.insert(0);
        int prevHighest = 0, curHighest = 0;

        for(pair<int, int> p : h) {
            if(p.second < 0) { // 左边
                m.insert(-p.second);
            } else { // 右边
                m.erase(m.find(p.second));
            }

            curHighest = *m.rbegin();

            if(prevHighest != curHighest) { // 到达了转折点
                vector<int> r(2, 0);
                r[0] = p.first;
                r[1] = curHighest;
                res.push_back(r);

                prevHighest = curHighest;
            }
        }

        return res;
    }
};