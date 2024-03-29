class Solution {
    public int reinitializePermutation(int n) {
        int[] target = new int[n];
        int[] perm = new int[n]; 
        for(int i = 0; i < n; i++) {
            target[i] = i;
            perm[i] = i;
        }

        int step = 0;
        while(true) {
            int[] arr = new int[n];
            for(int i = 0; i < n; i++) {
                if((i & 1) == 0) {
                    arr[i] = perm[i / 2];
                } else {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
            }
            perm = arr;
            step++;
            if(Arrays.equals(perm, target)) {
                break;
            }
        }

        return step;
    }
}