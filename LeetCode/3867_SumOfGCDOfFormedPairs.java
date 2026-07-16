class Solution {
    public long gcdSum(int[] nums) {
        int n = nums.length;
        int[] mx = new int[n];

        int max = 0;
        for (int i = 0; i < n; i++) {
            max = Math.max(max, nums[i]);
            mx[i] = max;
        }

        int[] prefixGcd = new int[n];
        for (int i = 0; i < n; i++) {
            prefixGcd[i] = gcd(nums[i], mx[i]);
        }

        Arrays.sort(prefixGcd);

        int l = 0, r = n - 1;
        long ans = 0;
        while (l < r) {
            ans += gcd(prefixGcd[l++], prefixGcd[r--]);
        }

        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}