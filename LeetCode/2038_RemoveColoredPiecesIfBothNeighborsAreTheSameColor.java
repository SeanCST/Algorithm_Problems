class Solution {
    public boolean winnerOfGame(String colors) {
        int count = 0;

        for(int i = 0; i < colors.length() - 2; i++) {
            if(colors.substring(i, i + 3).equals("AAA")) {
                count++;
            }
            if(colors.substring(i, i + 3).equals("BBB")) {
                count--;
            }
        }

        return count > 0;
    }
}