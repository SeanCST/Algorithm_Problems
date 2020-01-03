class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        map<int, bool> visited;
        sort(candidates.begin(), candidates.end());

        backtracking(res, cur, 0, candidates, target, visited);

        return res;
    }

    void backtracking(vector<vector<int>>& res, vector<int>& cur, int start, 
                      vector<int> candidates, int target, map<int, bool>& visited) {
        if(target == 0) {
            res.push_back(cur);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            if(i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1]) {
                continue; // 若前一个相同的还未加入，就加入当前这个，会造成重复
            }

            if(candidates[i] <= target) {
                cur.push_back(candidates[i]);
                visited[i] = true;
                backtracking(res, cur, i + 1, candidates, target - candidates[i], visited);
                visited[i] = false;
                cur.pop_back();
            }
        }
    }
};