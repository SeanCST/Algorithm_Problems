
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        String p = paragraph.toLowerCase();

        p = p.replaceAll("!", " ");
        p = p.replaceAll("\\?", " ");
        p = p.replaceAll("'", " ");
        p = p.replaceAll(",", " ");
        p = p.replaceAll(";", " ");
        p = p.replaceAll("\\.", " ");

        String[] splits = p.split(" ");
        HashMap<String, Integer> hashMap = new HashMap<String, Integer>();
        int maxCount = 0;
        String res = "";
        List<String> bannedList = Arrays.asList(banned);
        for (String s : splits) {
            if (s.equals("") || bannedList.contains(s)) {
                continue;
            }
            if (hashMap.containsKey(s)) {
                hashMap.put(s, hashMap.get(s) + 1);
            } else {
                hashMap.put(s, 1);
            }
            if (hashMap.get(s) > maxCount) {
                maxCount = hashMap.get(s);
                res = s;
            }
        }

        return res;
    }
}