class Solution {
    private int index = 0;

    public int calculate(String s) {
        int num = 0;
        Deque<Integer> stack = new ArrayDeque<>();
        char sign = '+';

        while (index < s.length()) {
            char c = s.charAt(index++);

            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            }

            if (c == '(') {
                num = calculate(s);
            }

            if (c == '+' || c == '-' || c == '*' || c == '/' || c == ')' || index == s.length()) {
                switch (sign) {
                    case '+' : 
                        stack.push(num); break;
                    case '-' : 
                        stack.push(-num); break;
                    case '*' : 
                        stack.push(stack.pop() * num); break;
                    case '/' : 
                        stack.push(stack.pop() / num); break;    
                }

                sign = c;
                num = 0;
            }

            if (c == ')') {
                break;
            }
        }

        int ans = 0;
        for (int x : stack) {
            ans += x;
        }

        return ans;
    }
}

// class Solution {

//     public int calculate(String s) {
//         Deque<Integer> nums = new ArrayDeque<>();
//         Deque<Character> ops = new ArrayDeque<>();

//         int n = s.length(), i = 0;
//         while (i < n) {
//             char c = s.charAt(i);

//             if (Character.isDigit(c)) {
//                 int num = 0;
//                 while (i < n && Character.isDigit(s.charAt(i))) {
//                     num = num * 10 + (s.charAt(i) - '0');
//                     i++;
//                 }
//                 nums.push(num);
//                 continue;
//             }

//             if (c == '(') {
//                 ops.push(c);
//             } else if (c == ')') {
//                 while (ops.peek() != '(') {
//                     compute(nums, ops);
//                 }
//                 ops.pop();
//             } else { // + - * /
//                 while (!ops.isEmpty() && precedence(ops.peek()) >= precedence(c)) {
//                     compute(nums, ops);
//                 }
//                 ops.push(c);
//             }

//             i++;
//         }

//         while (!ops.isEmpty()) {
//             compute(nums, ops);
//         }

//         return nums.pop();
//     }

//     private int precedence(char c) {
//         if (c == '+' || c == '-') {
//             return 1;
//         }
//         if (c == '*' || c == '/') {
//             return 2;
//         }
//         return 0;
//     }

//     private void compute(Deque<Integer> nums, Deque<Character> ops) {
//         char op = ops.pop();
//         int b = nums.pop();
//         int a = nums.pop(); 
//         switch (op) {
//             case '+' : 
//                 nums.push(a + b);
//                 break;
//             case '-' : 
//                 nums.push(a - b);
//                 break;
//             case '*' : 
//                 nums.push(a * b);
//                 break;
//             case '/' : 
//                 nums.push(a / b);
//                 break;
//         }
//     }
// }

