class Solution {
    public int clumsy(int N) {
        ArrayList<Integer> arrs = new ArrayList<>();
        Integer count = 0;
        Integer cur = 0;
        Integer sum = 0;
        for(int i = N; i >= 1; i--) {
            switch(count) {
                case 0 : 
                    cur = i;
                    break;
                case 1 : 
                    cur *= i;
                    break;
                case 2 : 
                    cur /= i;
                    arrs.add(cur);
                    break;
                case 3 :
                    sum += i;
                    break;
            }
            if(i == 1 && count < 2) {
                arrs.add(cur);
            }
            count++;
            if(count > 3) {
                count = 0;
            }
        }

        int res = arrs.get(0);
        for(int i = 1; i < arrs.size(); i++) {
            res -= arrs.get(i);
        }
        res += sum;

        return res;
    }
}