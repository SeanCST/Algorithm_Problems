class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();

        combine(candidates, target, 0, res, cur);

        return res;
    }

    private void combine(int[] candidates, int target, int start, List<List<Integer>> res, List<Integer> cur) {
        if(target == 0) {
            res.add(new ArrayList<>(cur));
            return;
        } 

        for(int i = start; i < candidates.length; i++) {
            if(candidates[i] <= target) {
                cur.add(candidates[i]);
                combine(candidates, target - candidates[i], i, res, cur);
                cur.remove(cur.size() - 1);
            }
        }
    }
}