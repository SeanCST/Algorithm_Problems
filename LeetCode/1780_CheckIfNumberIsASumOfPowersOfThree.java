class Solution {
    public boolean checkPowersOfThree(int n) {
        if(n < 2) {
            return true;
        } 
        if(n % 3 == 2) {
            return false;
        } else {
            return checkPowersOfThree(n / 3);
        }
    }
}