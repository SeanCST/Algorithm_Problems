/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     public int f(int x, int y);
 * };
 */

class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> res = new ArrayList<>();
        for(int i = 1; i <= z; i++) {
            int l = 1, r = z;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                int cus = customfunction.f(i, mid);
                if(cus == z) {
                    res.add(new ArrayList<Integer>(Arrays.asList(i, mid)));
                    break;
                } else if (cus < z) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return res;
    }
}