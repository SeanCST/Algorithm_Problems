class Solution {
private:
    vector<vector<int>> res;
    vector<int> cur;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int curSum = 0;

        // 排序做法
        // sort(candidates.begin(), candidates.end(), less<int>());
        // doCombinationSum(candidates, curSum, target);

        // 不排序做法
        backtracking(candidates, 0, target);

        return res;
    }

    void backtracking(vector<int> candidates, int start, int target) {
        if(target == 0) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                cur.push_back(candidates[i]);
                backtracking(candidates, i, target - candidates[i]);
                cur.pop_back();
            }
        }
    }

    // void doCombinationSum(vector<int> sortedCandidates, int curSum, int target) {
    //     if(curSum == target) {
    //         res.push_back(cur);
    //         return;
    //     }

    //     for(int num : sortedCandidates) {
    //         curSum += num;
    //         if(curSum > target) { // 因为 candidates 已经排序好了，故若当前 num 累加之后大于 target，后面的全都大于
    //             break;
    //         }

    //         if(cur.size() > 0 && cur[cur.size() - 1] > num) { // 保持每个结果都是升序，避免重复
    //             curSum -= num;
    //             continue;
    //         }
            
    //         cur.push_back(num);
    //         doCombinationSum(sortedCandidates, curSum, target);
    //         cur.pop_back();
    //         curSum -= num;
    //     }
    // }
};