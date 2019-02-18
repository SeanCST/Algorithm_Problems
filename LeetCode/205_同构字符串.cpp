class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
            
        map<char, char> s_m;
        map<char, char> t_m;

        for(int i = 0; i < s.length(); i++)
        {      
            if ((s_m.find(s[i]) != s_m.end() && s_m[s[i]] != t[i]) ||
                (t_m.find(t[i]) != t_m.end() && t_m[t[i]] != s[i])) 
            {  
                return false;
            } 
            else 
            {
                s_m[s[i]] = t[i];
                t_m[t[i]] = s[i];
            }
        }
        
        return true;
    }
};