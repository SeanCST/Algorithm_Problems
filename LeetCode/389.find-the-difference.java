/*
 * @lc app=leetcode.cn id=389 lang=java
 * @lcpr version=30204
 *
 * [389] 找不同
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public char findTheDifference(String s, String t) {
        int xor = 0;
        for (char c : s.toCharArray()) {
            xor ^= c;
        }

        for (char c : t.toCharArray()) {
            xor ^= c;
        }

        return (char) xor;

        // Map<Character, Integer> map = new HashMap<>();
        // for (char c : t.toCharArray()) {
        //     map.put(c, map.getOrDefault(c, 0) + 1);
        // }
        // for (char c : s.toCharArray()) {
        //     map.put(c, map.get(c) - 1);
        // }
        // for (Map.Entry<Character, Integer> entry : map.entrySet()) {
        //     if (entry.getValue() > 0) {
        //         return entry.getKey();
        //     }
        // }

        // return 'a';
    }
}
// @lc code=end



/*
// @lcpr case=start
// "abcd"\n"abcde"\n
// @lcpr case=end

// @lcpr case=start
// ""\n"y"\n
// @lcpr case=end

 */

