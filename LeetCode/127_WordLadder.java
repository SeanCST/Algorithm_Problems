class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> dict = new HashSet<>(wordList);
        if (!dict.contains(endWord)) {
            return 0;
        }
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        queue.offer(beginWord);
        visited.add(beginWord);
        int steps = 1;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String cur = queue.poll();
                if (cur.equals(endWord)) {
                    return steps;
                }

                char[] chars = cur.toCharArray();
                for (int j = 0; j < chars.length; j++) {
                    char old = chars[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        chars[j] = c;
                        String next = new String(chars);
                        if (dict.contains(next) && !visited.contains(next)) {
                            queue.offer(next);
                            visited.add(next);
                        }
                    }
                    chars[j] = old;
                }
            }
            steps++;
        }

        return 0;
    }
}