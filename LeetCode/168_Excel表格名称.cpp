class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0) {
            int k = n % 26;
            if(k == 0) k = 26;
            
            char c = 'A' + k - 1;
            res.insert(0, 1, c);
            n = n / 26;
            
            if(k == 26) n -= 1;
        }
        
        return res;
    }
};