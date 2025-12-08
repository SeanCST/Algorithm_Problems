class Solution {
    public boolean isNumber(String s) {
        Map[] states = {
            new HashMap<>() {{ put('s', 1); put('d', 2); put('.', 4); }}, // 0, start
            new HashMap<>() {{ put('d', 2); put('.', 4); }}, // 1, sign before e
            new HashMap<>() {{ put('d', 2); put('.', 3); put('e', 5); }}, // 2, digit before dot
            new HashMap<>() {{ put('d', 3); put('e', 5); }}, // 3, dot or digit after dot
            new HashMap<>() {{ put('d', 3); }}, // 4, dot (without digit before)
            new HashMap<>() {{ put('d', 7); put('s', 6); }}, // 5, e
            new HashMap<>() {{ put('d', 7); }}, // 6, sign after e
            new HashMap<>() {{ put('d', 7); }} // 7, digit after e
        };

        int p = 0;
        char t;
        for (char c : s.toCharArray()) {
            if (c >= '0' && c <= '9') {
                t = 'd';
            } else if (c == '+' || c == '-') {
                t = 's';
            } else if (c == '.') {
                t = '.';
            } else if (c == 'E' || c == 'e') {
                t = 'e';
            } else {
                t = '?';
            }
            if (states[p].containsKey(t)) {
                p = (int) states[p].get(t);
            } else {
                return false;
            }
        }

        return p == 2 || p == 3 || p == 7;
    }
}