class Solution {
    public boolean canChoose(int[][] groups, int[] nums) {
        int cur = 0;
        int i = 0;
        while(i < groups.length && cur < nums.length) {
            int[] group = groups[i];
            if(group[0] == nums[cur]) {
                int match = match(group, nums, cur);
                if(match == -1) {
                    cur++;
                } else {
                    cur = match;
                    i++;
                }
            } else {
                cur++;
            }
        }

        return i == groups.length;
    }

    private int match(int[] group, int[] nums, int begin) {
        int n = group.length;
        int i = 0;
        while(i < n && begin + i < nums.length) {
            if(group[i] != nums[begin + i]) {
                return -1;
            } else {
                i++;
            }
        }
        
        return i == n ? begin + n : -1;
    }
}