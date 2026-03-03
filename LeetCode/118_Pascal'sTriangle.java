class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(List.of(1));

        for (int i = 1; i < numRows; i++) {
            List<Integer> row = new ArrayList<>(i + 1);
            row.add(1);
            List<Integer> lastRow = ans.get(i - 1);
            for (int j = 0; j < i - 1; j++) {
                row.add(lastRow.get(j) + lastRow.get(j + 1));
            }
            row.add(1);
            ans.add(row);
        }

        return ans;
    }
}