class Solution {
    private int i = 0;

    public String decodeString(String s) {
        StringBuilder sb = new StringBuilder();
        int n = s.length();
        while (i < n) {
            int k = 0;
            while (Character.isDigit(s.charAt(i))) {
                k = k * 10 + (s.charAt(i) - '0');
                i++;
            }
            if (s.charAt(i) == '[') {
                i++;
                String bracketStr = decodeString(s);
                while (k-- > 0) {
                    sb.append(bracketStr);
                }
            }
            while (i < n && s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
                sb.append(s.charAt(i++));
            }
            if (i < n && s.charAt(i) == ']') {
                i++;
                return sb.toString();
            }
        }

        return sb.toString();
    }
}

// class Solution {
//     public String decodeString(String s) {
//         StringBuilder sb = new StringBuilder();
//         Deque<String> stack = new ArrayDeque<>();
        
//         int i = 0;
//         while (i < s.length()) {
//             if (Character.isDigit(s.charAt(i))) {
//                 int start = i++;
//                 while (i < s.length() && Character.isDigit(s.charAt(i))) {
//                     i++;
//                 }
//                 stack.push(s.substring(start, i));
//             } else if (s.charAt(i) == '[') {
//                 stack.push("[");
//                 i++;
//             } else if (s.charAt(i) == ']') {
//                 String str = stack.pop();
//                 while (!stack.peek().equals("[")) {
//                     str = stack.pop() + str;
//                 }
//                 String leftBracket = stack.pop();
//                 Integer num = Integer.valueOf(stack.pop());
//                 StringBuilder cur = new StringBuilder();
//                 while (num-- > 0) {
//                     cur.append(str);
//                 }
//                 if (stack.isEmpty()) {
//                     sb.append(cur.toString());
//                 } else {
//                     stack.push(cur.toString());
//                 }
//                 i++;
//             } else if (!stack.isEmpty()) {
//                 int start = i++;
//                 while (i < s.length() && Character.isLowerCase(s.charAt(i))) {
//                     i++;
//                 }
//                 stack.push(s.substring(start, i));
//             } else {
//                 int start = i++;
//                 while (i < s.length() && Character.isLowerCase(s.charAt(i))) {
//                     i++;
//                 }
//                 sb.append(s.substring(start, i));
//             }
//         }

//         return sb.toString();
//     }
// }