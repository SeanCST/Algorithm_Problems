class Solution {
private:
    int parent[1001];
    
    int findRoot(int x) {
        while(parent[x] != x) {
            x = parent[x];
            // parent[x] = parent[parent[x]];
            // x = parent[x];
        }
        return x;
    }

    bool unionRoot(int x, int y) {
        int xRoot = findRoot(x);
        int yRoot = findRoot(y);
        if(xRoot == yRoot) {
            return false;
        }
        
        parent[xRoot] = parent[yRoot]; // 使用路径压缩的方式来连接
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 1; i <= 1000; i++) {
            parent[i] = i;
        }

        for(auto edge : edges) {
            if(!unionRoot(edge[0], edge[1])) {
                return edge;
            }
        }

        return {};
    }
};