class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 只需检测有向图是否存在环
        vector<vector<int>> graphic(numCourses, vector<int>(0, 0));

        for(vector<int> pre : prerequisites) {
            graphic[pre[1]].push_back(pre[0]);
        }

        vector<int> flag(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if(hasCycle(graphic, flag, i)) {
                return false;
            }
        }

        return true;
    }

    bool hasCycle(vector<vector<int>>& graphic, vector<int>& flag, int curNode) {
        // 被标记为 1，证明在本次遍历过程中，第二次经过该节点，故存在环，直接返回 true
        if(flag[curNode] == 1) {
            return true;
        }
        // 被标记为 -1，证明在之前已经遍历过该节点，并且未发现环，故该点必不在环中，直接返回 false
        if(flag[curNode] == -1) { 
            return false;
        }

        flag[curNode] = 1;
        for(int nextNode : graphic[curNode]) {
            if(hasCycle(graphic, flag, nextNode)) {
                return true;
            }
        }
        flag[curNode] = -1;

        return false;
    }
};