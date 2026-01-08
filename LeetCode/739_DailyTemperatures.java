class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int len = temperatures.length;
        int[] res = new int[len];
        Deque<Integer> monoStack = new ArrayDeque<>();
        for (int i = 0; i < len; i++) {
            while (!monoStack.isEmpty() && temperatures[i] > temperatures[monoStack.peek()]) {
                int prevIndex = monoStack.pop();
                res[prevIndex] = i - prevIndex;
            }
            monoStack.push(i);
        }

        return res;
    }
}