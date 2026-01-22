class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int x : arr) {
            min = Math.min(min, x);
            max = Math.max(max, x);
        }

        if (min == max) {
            return true;
        }
        
        int n = arr.length;
        if ((max - min) % (n - 1) != 0) {
            return false;
        }
        int diff = (max - min) / (n - 1);

        boolean[] occured = new boolean[n];
        for (int x : arr) {
            int k = (x - min) / diff;
            if ((x - min) % diff != 0 || occured[k]) {
                return false;
            }
            occured[k] = true;
        }

        return true;
    }
}

// class Solution {
//     public boolean canMakeArithmeticProgression(int[] arr) {
//         if (arr.length < 2) {
//             return false;
//         }
//         Arrays.sort(arr);
//         int diff = arr[1] - arr[0];
//         for (int i = 2; i < arr.length; i++) {
//             if (arr[i] - arr[i - 1] != diff) {
//                 return false;
//             }
//         }

//         return true;
//     }
// }