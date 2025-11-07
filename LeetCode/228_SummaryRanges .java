class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> res = new ArrayList<>();
        if (nums.length == 0) {
            return res;
        }
        int start = nums[0];
        int i = 1;
        while (i <= nums.length) {
            if (i == nums.length || nums[i] != nums[i - 1] + 1) {
                StringBuilder sb = new StringBuilder();
                sb.append(start);
                if (nums[i - 1] > start) {
                    sb.append("->");
                    sb.append(nums[i - 1]);
                }
                res.add(sb.toString());
                if (i != nums.length) {
                    start = nums[i];
                } 
            }
            i++;
        }

        return res;
    }
}