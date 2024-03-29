class Solution {
    public String removeOuterParentheses(String s) {
        StringBuffer res = new StringBuffer();
        Deque<Character> stack = new ArrayDeque<>();
        
        for(int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            if(c == ')') {
                stack.pop();
            }
            if(!stack.isEmpty()) {
                res.append(c);
            }
            if(c == '(') {
                stack.push(c);
            }
        }

        return res.toString();
    }
}