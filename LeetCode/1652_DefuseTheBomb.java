class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        int[] res = new int[n];
        int e = k > 0 ? 1 : (k == 0 ? 0 : -1);
        
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = e; j != k + e; j += e) {
                sum += code[(i + j + n) % n];
            }
            res[i] = sum;
        }

        return res;
    }
}