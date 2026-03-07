class RandomizedSet {
    private Map<Integer, Integer> map;
    private int[] nums;
    private Random random;
    private int index;

    public RandomizedSet() {
        map = new HashMap<>();
        nums = new int[200000];
        random = new Random();
        index = -1;
    }
    
    public boolean insert(int val) {
        if (map.containsKey(val)) {
            return false;
        }

        map.put(val, ++index);
        nums[index] = val;

        return true;
    }
    
    public boolean remove(int val) {
        if (!map.containsKey(val)) {
            return false;
        }

        int removedIdx = map.remove(val);
        if (removedIdx != index) {
            map.put( nums[index], removedIdx);
        }
        nums[removedIdx] = nums[index--];
        
        return true;        
    }
    
    public int getRandom() {
        return nums[random.nextInt(index + 1)];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */