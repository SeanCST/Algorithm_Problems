class Solution {
    public void hanota(List<Integer> A, List<Integer> B, List<Integer> C) {
        move(A, B, C, A.size());
    }

    private void move(List<Integer> source, List<Integer> transit, List<Integer> target, int n) {
        if (n == 1) {
            target.add(source.remove(source.size() - 1));
            return;
        }

        move(source, target, transit, n - 1);
        move(source, transit, target, 1);
        move(transit, source, target, n - 1);
    }
}