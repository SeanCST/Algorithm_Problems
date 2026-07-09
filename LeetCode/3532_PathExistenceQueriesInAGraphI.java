class Solution {
    private int[] parent;

    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        boolean[] ans = new boolean[queries.length];
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                union(i, i - 1);
            }
        }

        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            int u = query[0], v = query[1];
            if (isConnected(u, v)) {
                ans[i] = true;
            }
        }

        return ans;
    }

    private void union(int x, int y) {
        int xRoot = find(x), yRoot = find(y);
        if (xRoot != yRoot) {
            parent[xRoot] = yRoot;
        }
    }

    private int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    private boolean isConnected(int x, int y) {
        return parent[x] == parent[y];
    }
}