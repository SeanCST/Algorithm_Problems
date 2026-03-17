class Solution {
    public int singleNumber(int[] nums) {
        int[] cnt = new int[32];
        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                cnt[i] += (num >> i) & 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans += (cnt[i] % 3) << i;
        }

        return ans;
    }
}

// class Solution {
//     public int singleNumber(int[] nums) {
//         int a = 0, b = 0;
//         for (int num : nums) {
//             b = ~a & (b ^ num);
//             a = ~b & (a ^ num);
//         }

//         return b;
//     }
// }