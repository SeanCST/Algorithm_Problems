class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<>();

        int l = 0, res = 0;
        for (int r = 0; r < s.length(); r++) {
            Character c = s.charAt(r);
            if (map.containsKey(c)) {
                l = Math.max(l, map.get(c));
            }

            res = Math.max(res, r - l + 1);
            map.put(c, r + 1);
        }

        return res;
    }
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        map<char, bool> m;
        int j = 0; // abcdefacd
        for(int i = 0; i < s.length(); i++) {
            if(m[s[i]]) {
                while(s[j] != s[i]) {
                    m[s[j++]] = false;
                }
                res = max(res, i - j);
                j++;
            } else {
                res = max(res, i - j + 1);
            }
            m[s[i]] = true;
        }
        
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n <= 1) {
            return n;
        }

        map<char, bool> m;
        int l = 0, r = 0;
        int longestLength = 0;
        int curLen = 0;
        for(int i = 0; i < n; i++) {
            r = i;
            if(m[s[i]]) {
                curLen = r - l;
                while(l <= r) {
                    if(s[l] == s[i]) {
                        l++;
                        break;
                    } else {
                        m[s[l++]] = false;
                    }
                }
            } else {
                curLen = r - l + 1;
            }
            longestLength = max(curLen, longestLength);
            m[s[i]] = true;
        }

        return longestLength;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n <= 1) {
            return n;
        }
        int res = 1;
        set<char> occurances;
        int i = 0, j = 0;
        while(j < n) {
            if(occurances.find(s[j]) == occurances.end()) { // 在本子串中未出现过
                occurances.insert(s[j]);
            } else { // 在本子串中出现过
                res = max(res, j - i);
                while(s[i] != s[j]) {
                    occurances.erase(s[i]);
                    i++;
                }
                i++; // 指向一个新的子串开头
            }
            j++;
        }
        res = max(res, j - i);
        
        return res;
    }
};