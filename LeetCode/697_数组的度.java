class Solution {
    public int findShortestSubArray(int[] nums) {
        HashMap<Integer, Integer> degreeMap = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> firstIdxMap = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> lastIdxMap = new HashMap<Integer, Integer>();

        Integer maxDegree = 0;

        for (Integer i = 0; i < nums.length; i++) {
            Integer num = nums[i];
            if (!degreeMap.containsKey(num)) {
                degreeMap.put(num, 1);
            } else {
                degreeMap.put(num, degreeMap.get(num) + 1);
            }

            maxDegree = Math.max(degreeMap.get(num), maxDegree);

            if (!firstIdxMap.containsKey(num)) {
                firstIdxMap.put(num, i);
            }
            lastIdxMap.put(num, i);
        }

        Integer res = Integer.MAX_VALUE;
        for (Integer num : nums) {
            if (degreeMap.get(num) == maxDegree) {
                res = Math.min(lastIdxMap.get(num) - firstIdxMap.get(num), res);
            }
        }

        return res + 1;
    }
}