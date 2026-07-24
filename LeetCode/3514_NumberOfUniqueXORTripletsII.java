class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n = nums.length;
        int max = 0;
        for (int num : nums) {
            max = Math.max(max, num);
        }
        int u = 1;
        while (u <= max) {
            u <<= 1;
        }

        boolean[] s = new boolean[u];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                s[nums[i] ^ nums[j]] = true;
            }
        }

        boolean[] t = new boolean[u];
        for (int x = 0; x < u; x++) {
            if (!s[x]) {
                continue;
            }
            for (int num : nums) {
                t[num ^ x] = true;
            }
        }

        int ans = 0;
        for (boolean b : t) {
            ans += b ? 1 : 0;
        }

        return ans;
    }
}