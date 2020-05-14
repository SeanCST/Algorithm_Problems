class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        
        vector<vector<int>> adjecency(numCourses, vector<int>(0, 0));
        vector<int> indegrees(numCourses, 0);
        for(vector<int> pre : prerequisites) {
            indegrees[pre[0]]++;
            adjecency[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegrees[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            numCourses--;
            int f = q.front();
            q.pop();
            res.push_back(f);
            for(int adj : adjecency[f]) {
                indegrees[adj]--;
                if(indegrees[adj] == 0) {
                    q.push(adj);
                }
            }
        }
        if(numCourses == 0) {
            return res;
        } else {
            vector<int> empty;
            return empty;
        }
    }
};