class Solution {
    public boolean squareIsWhite(String coordinates) {
        int i = coordinates.charAt(0) - 'a';
        int j = coordinates.charAt(1) - '1';

        if(i % 2 == 0) {
            return j % 2 == 1;
        } else {
            return j % 2 == 0;
        }
    }
}