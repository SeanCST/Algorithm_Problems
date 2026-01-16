class Solution {
    public String removeKdigits(String num, int k) {
        Deque<Character> deque = new ArrayDeque<>();

        for (int i = 0; i < num.length(); i++) {
            char digit = num.charAt(i);
            while (!deque.isEmpty() && k > 0 && deque.peekLast() > digit) {
                deque.pollLast();
                k--;
            }
            deque.offerLast(digit);
        }

        while (k-- > 0) {
            deque.pollLast();
        }

        StringBuilder sb = new StringBuilder();
        boolean leadingZero = true;
        while (!deque.isEmpty()) {
            char digit = deque.pollFirst();
            if (leadingZero && digit == '0') {
                continue;
            }
            sb.append(digit);
            leadingZero = false;
        }

        return sb.length() == 0 ? "0" : sb.toString();
    }
}