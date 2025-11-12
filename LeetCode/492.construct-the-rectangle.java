class Solution {
    public int[] constructRectangle(int area) {
        int w = (int) Math.sqrt(area);
        while (area % w != 0) {
            w--;
        }

        return new int[]{area / w, w};

        // int[] res = new int[2];
        // int minDiff = Integer.MAX_VALUE;
        // for (int w = 1; w <= area / w; w++) {
        //     if (area % w == 0) {
        //         int l = area / w;
        //         int diff = l - w;
        //         if (diff < minDiff) {
        //             minDiff = diff;
        //             res[0] = l;
        //             res[1] = w;
        //         }
        //     }
        // }

        // return res;
    }
}