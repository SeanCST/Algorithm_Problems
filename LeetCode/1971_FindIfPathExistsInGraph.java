class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        if(source == destination) {
            return true;
        }
        UnionFind uf = new UnionFind(n);
        for(int[] edge : edges) {
            uf.union(edge[0], edge[1]);
        }

        return uf.connect(source, destination);
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public void union(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot) {
            if(rank[xRoot] > rank[yRoot]) {
                parent[yRoot] = parent[xRoot];
            } else if(rank[xRoot] < rank[yRoot]) {
                parent[xRoot] = parent[yRoot];
            } else {
                parent[yRoot] = xRoot;
                rank[xRoot]++;
            }
        }
    }

    public int find(int x) {
        if(x != parent[x]) {
            parent[x] = find(parent[x]);
        } 
        return parent[x];
    }

    public boolean connect(int x, int y) {
        return find(x) == find(y);
    }

}