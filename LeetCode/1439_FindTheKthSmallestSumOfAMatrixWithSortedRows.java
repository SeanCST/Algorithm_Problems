class Solution {
    public int kthSmallest(int[][] mat, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue(Comparator.reverseOrder());
        pq.add(0);
        for(int[] row: mat) {
            List<Integer> currents = new ArrayList<>(pq);
            pq.clear();
            for(int current : currents) {
                for(int num : row) {
                    pq.add(current + num);
                }
            }
            while(pq.size() > k) {
                pq.poll();
            }
        }

        return pq.peek();
    }
}