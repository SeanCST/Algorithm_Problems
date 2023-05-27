class Solution {
    public double[] sampleStats(int[] count) {
        double min = -1, max = 256, mode = 0, maxCount = 0, sumCount = 0;
        double sum = 0;
        for(int i = 0; i < count.length; i++) {
            if(count[i] > 0) {
                max = i;
                if(min == -1) {
                    min = i;
                }
                if(maxCount < count[i]) {
                    maxCount = count[i];
                    mode = i;
                }
                sum += (double)i * count[i];
                sumCount += count[i];
            }
        }
        int curCount = 0;
        boolean isOdd = sumCount % 2 == 1;
        double median = -1;
        int lastNumber = 0;
        for(int i = 0; i < count.length; i++) {
            if(count[i] > 0) {
                curCount += count[i];
                if((int)sumCount / 2 + 1 <= curCount) {
                    if(isOdd) {
                        median = i;
                    } else {
                        if(curCount - count[i] == sumCount / 2) {
                            median = (i + lastNumber) / 2.0;
                        } else {
                            median = i;
                        }
                    }
                    if(median != -1) {
                        return new double[]{min, 
                                            max, 
                                            (double)sum / sumCount, 
                                            median, 
                                            mode};
                    }
                }
                lastNumber = i;
            }
        }

        return null;
    }
}