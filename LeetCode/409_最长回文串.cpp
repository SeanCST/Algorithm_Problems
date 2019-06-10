class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for(char c : s) {
            m[c]++;
        }
        map<char, int>::iterator iter = m.begin();
        int res = 0;
        // bool hasOne = false;
        while(iter != m.end()) {
            int curCount = iter->second;
            if(curCount > 1) {
                if(curCount % 2 == 0) {
                    res += curCount;
                } else {
                    res += curCount - 1;
                    // hasOne = true;
                }
            } 
            // else if(curCount == 1) {
            //     hasOne = true;
            // }
            iter++;
        }
        
        // if(hasOne) 
        //     res++;
        
        if(res < s.length())
            res++;
        
        return res;
    }
};