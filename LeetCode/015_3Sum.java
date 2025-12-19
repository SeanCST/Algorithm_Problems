class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        if (nums.length < 3) {
            return res;
        }

        int n = nums.length;
        for (int first = 0; first < n - 2; first++) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int third = n - 1;
            for (int second = first + 1; second < n - 1; second++) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                while (second < third && nums[third] > -(nums[first] + nums[second])) {
                    third--;
                }
                if (second == third) {
                    break;
                }
                if (nums[third] == -(nums[first] + nums[second])) {
                    res.add(List.of(nums[first], nums[second], nums[third]));
                }
            }
        }
        
        return res;
    }
}