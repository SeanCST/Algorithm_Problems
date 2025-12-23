class Solution {
    public List<List<Integer>> permute(int[] nums) {
        boolean[] visited = new boolean[nums.length];
        List<Integer> path = new ArrayList<>();
        List<List<Integer>> res = new ArrayList<>();
        dfs(nums, visited, path, res);

        return res;
    }

    private void dfs(int[] nums, boolean[] visited, List<Integer> path, List<List<Integer>> res) {
        if (path.size() == nums.length) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (visited[i] == false) {
                int num = nums[i];
                visited[i] = true;
                path.add(num);
                dfs(nums, visited, path, res);
                path.remove(path.size() - 1);
                visited[i] = false;
            }
        }
    }

}