class Solution {
    public List<Integer> partitionLabels(String s) {
        List<Integer> res = new ArrayList<>();
        int[] last = new int[26];
        int len = s.length();
        for (int i = 0; i < len; i++) {
            last[s.charAt(i) - 'a'] = i;
        }  
        
        int l = 0, r = last[s.charAt(0) - 'a'];
        for (int i = 0; i < len; i++) {
            r = Math.max(last[s.charAt(i) - 'a'], r);
            if (r == i) {
                res.add(r - l + 1);
                l = r + 1;
            }
        }

        return res;
    }
}