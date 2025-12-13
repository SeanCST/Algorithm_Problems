class Solution {
    public static void main(String[] args) {
        Solution s = new Solution();
        String result = s.mergeAlternately("abc", "pqr");
        System.out.println(result);
    }

    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder();
        int i = 0, j = 0;

        while (i < word1.length() && j < word2.length()) {
            sb.append(word1.charAt(i++));
            sb.append(word2.charAt(j++));
        }

        sb.append(word1.substring(i, word1.length()));
        sb.append(word2.substring(j, word2.length()));

        return sb.toString();
    }
}