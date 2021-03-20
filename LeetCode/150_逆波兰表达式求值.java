class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stk = new Stack<Integer>();

        for(String token : tokens) {
            if(token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/") ) {
                Integer num1 = stk.pop();
                Integer num2 = stk.pop();
                if(token.equals("+")) {
                    stk.push(num2 + num1);
                } else if(token.equals("-")) {
                    stk.push(num2 - num1);
                } else if(token.equals("*")) {
                    stk.push(num2 * num1);
                } else if(token.equals("/")) {
                    stk.push(num2 / num1);
                } 
            } else {
                stk.push(Integer.valueOf(token));
            }
        }
        
        return stk.peek();
    }
}