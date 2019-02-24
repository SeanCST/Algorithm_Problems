class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        
        map<char, int> m;
        for(int i = 0; i < s.length(); i++) {
            m[s[i]]++;
            m[t[i]]--;
        }
        
        map<char, int>::iterator iter = m.begin();
        while(iter != m.end()) {
            if(iter->second != 0) 
                return false;
            iter++;
        }
        
        return true;
    }
};