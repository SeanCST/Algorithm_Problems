class Solution {
    List<int[]>[] graph;
    int[] ans;

    public int[] minEdgeReversals(int n, int[][] edges) {
        graph = new ArrayList[n];
        ans = new int[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] e : edges) {
            int u = e[0], v = e[1];
            graph[u].add(new int[]{v, 0});
            graph[v].add(new int[]{u, 1});
        }

        dfs(0, -1); // use 0 as root
        reroot(0, -1); // reroot for dp
        return ans;
    }

    private void dfs(int u, int parent) {
        for (int[] e : graph[u]) {
            int v = e[0], cost = e[1];
            if (v == parent) {
                continue;
            }
            ans[0] += cost;
            dfs(v, u);
        }
    }

    private void reroot(int u, int parent) {
        for (int[] e : graph[u]) {
            int v = e[0], cost = e[1];

            if (v == parent) {
                continue;
            }

            if (cost == 0) {
                ans[v] = ans[u] + 1;
            } else {
                ans[v] = ans[u] - 1;
            }

            reroot(v, u);
        }
    }
}