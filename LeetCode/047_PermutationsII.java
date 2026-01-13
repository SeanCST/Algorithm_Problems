class Solution {
    private boolean[] visited;
    private List<List<Integer>> res;
    private List<Integer> perm;

    public List<List<Integer>> permuteUnique(int[] nums) {
        res = new ArrayList<>();
        perm = new ArrayList<>();
        visited = new boolean[nums.length];
        Arrays.sort(nums);

        backtrace(nums, 0);

        return res;
    }

    private void backtrace(int[] nums, int idx) {
        if (nums.length == idx) {
            res.add(new ArrayList<>(perm));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (visited[i] || (i > 0 && nums[i - 1] == nums[i] && !visited[i - 1])) {
                continue;
            }
            perm.add(nums[i]);
            visited[i] = true;
            backtrace(nums, idx + 1);
            visited[i] = false;
            perm.remove(idx);
        }
    }
}