class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> res = new ArrayList<>();

        for(int i = left; i <= right; i++) {
            if(isSelfDividing(i)) {
                res.add(new Integer(i));
            }
        }

        return res;
    }

    private boolean isSelfDividing(int n) {
        int cur = n;
        while(cur != 0) {
            int k = cur % 10;
            if(k == 0 || n % k != 0) {
                return false;
            } else {
                cur /= 10;
            }
        }

        return true;
    }
}