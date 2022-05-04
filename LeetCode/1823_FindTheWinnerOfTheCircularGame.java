class Solution {
    public int findTheWinner(int n, int k) {
        // f(N, M) = (f(N − 1, M) + M) % n

        int p = 0;
        for(int i = 2; i <= n; i++) {
            p = (p + k) % i;
        }

        return p + 1;
    }
}

// class Solution {
//     public int findTheWinner(int n, int k) {
//         Queue<Integer> q = new LinkedList<>();
//         for(int i = 1; i <= n; i++) {
//             q.add(i);
//         }

//         for(int i = 1; i < n; i++) {
//             for(int j = 1; j < k; j++) {
//                 q.add(q.poll());
//             }
//             q.poll();
//         }

//         return q.poll();
//     }
// }