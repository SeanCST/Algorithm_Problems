class Solution {
    public boolean areNumbersAscending(String s) {
        String[] arr = s.split(" ");
        int curMax = 0;
        for(String str : arr) {
            if(str.charAt(0) > '0' && str.charAt(0) <= '9') {
                int num = Integer.parseInt(str);
                if(curMax >= num) {
                    return false;
                }
                curMax = num;
            }
        }
        
        return true;
    }
}