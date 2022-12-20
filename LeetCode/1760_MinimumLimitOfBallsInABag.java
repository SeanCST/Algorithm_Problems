class Solution {
    public int minimumSize(int[] nums, int maxOperations) {
        int left = 1, right = Arrays.stream(nums).max().getAsInt();
        int res = 0;

        while(left <= right) {
            int y = left + (right - left) / 2;
            int ops = 0;
            for(int num : nums) {
                ops += (num - 1) / y;
            }
            
            if(ops <= maxOperations) {
                res = y;
                right = y - 1;
            } else {
                left = y + 1;
            }
        }

        return res;
    }
}