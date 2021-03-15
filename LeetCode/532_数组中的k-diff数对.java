class Solution {
    public int findPairs(int[] nums, int k) {
        HashMap<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            Integer num = nums[i];
            if (m.containsKey(num)) {
                m.put(num, m.get(num) + 1);
            } else {
                m.put(num, 1);
            }
        }

        int res = 0;
        for (Integer num : m.keySet()) {
            if(k == 0) {
                if(m.get(num) > 1) {
                    res += 1;
                }
            } else {
                if (m.containsKey(num + k)) {
                    res += 1;
                }
            }
        }
        
        return res;
    }
}