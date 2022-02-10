class Solution {
    public List<String> simplifiedFractions(int n) {
        List<String> res = new ArrayList<String>();

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                if(gcd(i, j) == 1) {
                    res.add(j + "/" + i);
                }
            }
        }

        return res;
    }

    private int gcd(int a, int b) {
        return b > 0 ? gcd(b, a % b) : a;
    }
}