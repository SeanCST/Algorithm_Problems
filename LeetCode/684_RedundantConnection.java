class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] parent = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (int[] edge : edges) {
            if (!union(parent, edge[0], edge[1])) {
                return edge;
            }
        }

        return new int[0];
    }

    private boolean union(int[] parent, int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);
        if (xRoot == yRoot) {
            return false;
        }

        parent[xRoot] = yRoot;
        return true;
    }

    private int find(int[] parent, int x) {
        if (x != parent[x]) {
            parent[x] = find(parent, parent[x]);
        }

        return parent[x];
    }
}