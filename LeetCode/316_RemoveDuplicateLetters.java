class Solution {
    public String removeDuplicateLetters(String s) {
        int[] count = new int[26];
        boolean[] exist = new boolean[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }

        Deque<Character> stack = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            count[c - 'a']--;
            if (exist[c - 'a']) {
                continue;
            }

            while (!stack.isEmpty() && stack.peek() > c && count[stack.peek() - 'a'] > 0) {
                exist[stack.pop() - 'a'] = false;
            }

            stack.push(c);
            exist[c - 'a'] = true;
        }

        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.insert(0, stack.pop());
        }

        return sb.toString();
    }
}