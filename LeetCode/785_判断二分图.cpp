
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(colors[i] == -1 && !dfs(graph, colors, i, 0)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int curNode, int curColor) {
        if(colors[curNode] != -1) {
            return colors[curNode] == curColor;
        }

        colors[curNode] = curColor;

        for(int k : graph[curNode]) {
            if(!dfs(graph, colors, k, 1 - curColor)) {
                return false;
            }
        }
        
        return true;
    }
};


class Solution {
    int n;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        if (n == 1) {
            return graph[0].size() == 0;
        }
        vector<int> colors(n, 0);
        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; i++) {
            if(graph[i].size() > 0) {
                colors[i] = 1;
                if(!dfs(graph, colors, visited, i)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, vector<bool>& visited, int i) {
        if(i == n || visited[i] == true) {
            return true;
        }
        visited[i] = true;
        int toPaintColor = colors[i] == 1 ? 2 : 1; // 给 i 结点的邻边要涂上的颜色
        for(int k : graph[i]) {
            if(colors[k] == 0) { // 还未涂色，进行深度优先搜索
                colors[k] = toPaintColor;
                if(!dfs(graph, colors, visited, k)) {
                    return false;
                }
            } else if (colors[k] != toPaintColor){ // 已经涂色，并且涂的颜色不对
                return false;
            }
        }
        
        return true;
    }
};