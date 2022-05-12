class Solution {
    public int minDeletionSize(String[] strs) {
        if(strs == null || strs.length == 0) {
            return 0;
        }
        int len = strs[0].length();
        int res = 0;
        for(int i = 0; i < len; i++) {
            boolean needDelete = false;
            for(int j = 1; j < strs.length; j++) {
                if(strs[j].charAt(i) < strs[j - 1].charAt(i)) {
                    needDelete = true;
                    break;
                }
            }
            res = needDelete ? res + 1 : res;
        }

        return res;
    }
}