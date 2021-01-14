class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> res = new ArrayList<Boolean>();

        int prefix = 0;
        for (int i = 0; i < A.length; i++) {
            prefix = ((prefix << 1) + A[i]) % 5;
            res.add(prefix == 0);
        }

        return res;
    }
}