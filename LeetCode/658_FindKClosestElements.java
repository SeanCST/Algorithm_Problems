class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int loc = 0;
        int n = arr.length;
        if(x >= arr[n - 1]) {
            loc = n - 1;
        } else if(x >= arr[0]) {
            for(int i = 0; i < n - 1; i++) {
                if((arr[i] < x && arr[i + 1] > x) || arr[i] == x) {
                    loc = i;
                    break;
                }
            }
        }

        List<Integer> res = new ArrayList<>();
        int l = loc, r = loc + 1;
        while(k > 0) {
            if(r >= n) {
                res.add(0, arr[l--]);
            } else if(l < 0) {
                res.add(arr[r++]);
            } else if(x - arr[l] <= arr[r] - x) {
                res.add(0, arr[l--]);
            } else {
                res.add(arr[r++]);
            }
            k--;
        }

        return res;

    }
}