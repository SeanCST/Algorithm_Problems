class Solution {
    public String longestDiverseString(int a, int b, int c) {
        String res = "";

        while(a + b + c > 0) {
            int len = res.length();
            char ch = maxRemainingCountChar(a, b, c);
            if(len >= 2 && res.charAt(len - 1) == ch && res.charAt(len - 2) == ch) {
                ch = secondMaxRemainingCountChar(a, b, c);  
            }

            if(ch == 'a') {
                if(a == 0) {
                    return res;
                } else {            
                    res += 'a';
                    a--;
                }
            } else if(ch == 'b') {
                if(b == 0) {
                    return res;
                } else {            
                    res += 'b';
                    b--;
                }
            } else if(ch == 'c') {
                if(c == 0) {
                    return res;
                } else {            
                    res += 'c';
                    c--;
                }
            } 
        }

        return res;
    }

    private char maxRemainingCountChar(int a, int b, int c) {
        if(a >= b && a >= c) {
            return 'a';
        } else if(b >= a && b >= c) {
            return 'b';
        } else if(c >= b && c >= a) {
            return 'c';
        }

        return 'x';
    }

    private char secondMaxRemainingCountChar(int a, int b, int c) {
        if((b >= c && c >= a) || (a >= c && c >= b)) {
            return 'c';
        } else if((a >= b && b >= c) || (c >= b && b >= a)) {
            return 'b';
        } else if((b >= a && a >= c) || (c >= a && a >= b)) {
            return 'a';
        }

        return 'x';
    }
}