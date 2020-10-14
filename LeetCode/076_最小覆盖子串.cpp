class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> need;
        for(char c : t) {
            need[c]++;
        }

        string res;
        int l = 0, r = 0;
        int count = t.length();

        while(r < s.length()) {
            char c = s[r];
            if(need[c] > 0) {
                count--;
            }
            need[c]--;

            if(count == 0) {
                while(l < r && need[s[l]] < 0) {
                    need[s[l]]++;
                    l++;
                }

                if(res.length() == 0 || r - l + 1 < res.length()) {
                    res = s.substr(l, r - l + 1);
                }

                need[s[l]]++;
                l++;
                count++;
            }

            r++;
        }

        return res;
    }
};