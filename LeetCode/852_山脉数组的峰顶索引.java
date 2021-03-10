class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int l = 0, r = arr.length - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(mid == 0) {
                l++;
            } else if(mid == arr.length - 1) {
                r--;
            } else {
                if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                    return mid;
                } else if(arr[mid] > arr[mid - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return l;
    }
}