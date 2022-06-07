class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int maxVal = 1;
        for(int i = 0; i < piles.length; i++) {
            maxVal = maxVal < piles[i] ? piles[i] : maxVal;
        }

        int left = 1;
        int right = maxVal;

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(calculateTime(piles, mid) > h) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    private int calculateTime(int[] piles, int speed) {
        int time = 0;
        for(int pile : piles) {
            // 向上取整
            time += (pile + speed - 1) / speed;
        }
        return time;
    }
}