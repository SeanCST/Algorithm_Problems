class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> list = new ArrayList<>();

        for (int i = 1; i < 9; i++) {
            int cur = i;
            for (int j = i + 1; j <= 9; j++) {
                cur = cur * 10 + j;
                if (cur >= low && cur <= high) {
                    list.add(cur);
                }
            }
        }
        Collections.sort(list);

        return list;
    }
}