class Solution {
    public int numRabbits(int[] answers) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for(Integer answer : answers) {
            if(map.containsKey(answer)) {
                map.put(answer, map.get(answer) + 1);
            } else {
                map.put(answer, 1);
            }
        }
        
        int res = 0;
        Set<Integer> keySet = map.keySet();
        for (Integer key : keySet) {
            int group = key + 1; // 兔子颜色相同为一组，一组内有几只
            int value = map.get(key); // 这 value 只兔子都是有 key 个相同颜色的伙伴
            if(value % group == 0) { // 如果这 value 只兔子刚好可以划分为几组，则不需要添加其他的兔子进来
                res += value; 
            } else { // 如果这 value 只兔子不能刚好划分，则需要添加其他几只兔子来组成同一种颜色的一组
                res += value + (group - value % group);
            }

            // if (key == 0) {
            //     res += map.get(key);
            // } else if(key + 1 >= map.get(key)) {
            //     res += key + 1;
            // } else {
            //     int x = key + 1;
            //     int value = map.get(key);
            //     if(value % x == 0) {
            //         res += value;
            //     } else {
            //         res += value + (x - value % x);
            //     }
            // }
        }
        
        return res;
    }
}