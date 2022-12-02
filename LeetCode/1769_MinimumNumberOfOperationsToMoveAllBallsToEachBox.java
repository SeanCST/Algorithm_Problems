class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int left = boxes.charAt(0) - '0', right = 0, operation = 0;
        for(int i = 1; i < n; i++) {
            if(boxes.charAt(i) == '1') {
                operation += i;
                right++;
            }
        }
        int[] res = new int[n];
        res[0] = operation;

        for(int i = 1; i < n; i++) {
            operation += left - right;
            if(boxes.charAt(i) == '1') {
                left++;
                right--;
            }
            res[i] = operation;

        }

        return res;
    }
}

// class Solution {
//     public int[] minOperations(String boxes) {
//         int n = boxes.length();
//         int[] res = new int[n];

//         for(int i = 0; i < n; i++) {
//             int temp = 0;
//             for(int j = 0; j < n; j++) {
//                 if(i != j && boxes.charAt(j) == '1') {
//                     temp += Math.abs(i - j);
//                 }
//                 res[i] = temp;
//             }
//         }

//         return res;
//     }
// }