class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] splits = s.split(" ");
        HashMap<Character, String> hm = new HashMap<>();

        if(pattern.length() != splits.length) {
            return false;
        }

        for(int i = 0; i < pattern.length(); i++) {
            Character c = pattern.charAt(i);
            if(hm.containsKey(c)) {
                if (!hm.get(c).equals(splits[i])) {
                    return false;
                }
            } else {
                if (hm.containsValue(splits[i])) {
                    return false;
                }
                hm.put(c, splits[i]);
            }
        }

        return true;
    }
}