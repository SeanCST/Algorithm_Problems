class Solution {
    public int[] smallestK(int[] arr, int k) {
        int[] res = new int[k];
        if (k == 0) {
            return res;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>(
            (num1, num2) -> num2 - num1
        );

        for (int i = 0; i < k; i++) {
            pq.offer(arr[i]);
        }
        for (int i = k; i < arr.length; i++) {
            if (pq.peek() > arr[i]) {
                pq.poll();
                pq.offer(arr[i]);
            }
        }
        for(int i = k - 1; i >= 0; i--) {
            res[i] = pq.poll();
        }

        return res;
    }
}