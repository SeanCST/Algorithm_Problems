class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> map = new HashMap<>();
        int res = 0, l = 0;
        for (int r = 0; r < fruits.length; r++) {
            int fruitType = fruits[r];
            map.put(fruitType, map.getOrDefault(fruitType, 0) + 1);
            while (map.size() > 2) {
                int lFruit = fruits[l];
                l++;
                int count = map.get(lFruit) - 1;
                if (count == 0) {
                    map.remove(lFruit);
                } else {
                    map.put(lFruit, count);
                }
            }
            res = Math.max(res, r - l + 1);
        }

        return res;
    }
}