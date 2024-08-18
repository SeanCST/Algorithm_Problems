class Solution {
    public boolean checkRecord(String s) {
        int absentCount = 0, consecutiveLateCount = 0;
        for (char c : s.toCharArray()) {
            if (c == 'A') {
                absentCount ++;
                if (absentCount >=2 ) {
                    return false;
                }
            } else if (c == 'L') {
                consecutiveLateCount ++;
                if (consecutiveLateCount == 3) {
                    return false;
                }
            } 
            
            if (c != 'L') {
                consecutiveLateCount = 0;
            }
        }

        return true;
    }
}