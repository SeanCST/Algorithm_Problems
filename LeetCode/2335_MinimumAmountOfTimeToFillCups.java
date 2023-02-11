class Solution {
    public int fillCups(int[] amount) {

        int total = Arrays.stream(amount).sum();
        int max = Arrays.stream(amount).max().getAsInt();

        return total <= 2 * max ? max : (total + 1) / 2;


        // int res = 0;
        // Arrays.sort(amount);        
        // while(amount[1] > 0) {
        //     amount[2]--;
        //     amount[1]--;
        //     res++;
        //     Arrays.sort(amount);        
        // }

        // res += amount[2];
        
        // return res;
    }
}