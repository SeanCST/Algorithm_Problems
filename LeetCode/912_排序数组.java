class Solution {
    public int[] sortArray(int[] nums) {
        quickSort(nums, 0, nums.length - 1);
        return nums;
    }

    public void quickSort(int[] nums, int left, int right){
        if(left < right){
            int pivot = partition(nums, left, right);
            quickSort(nums, left, pivot - 1);
            quickSort(nums, pivot + 1, right);
        }
    }

    public int partition(int[] nums, int left, int right){
        int pivot = nums[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if(nums[j] <= pivot) {
                i++;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        nums[right] = nums[i + 1];
        nums[i + 1] = pivot;
        return i + 1;
    }

    public int[] insertSort(int[] nums){
        for(int i = 1; i < nums.length; i++) {
            int cur = nums[i];
            int j = i - 1;
            for(; j >= 0 && cur < nums[j]; j--) {
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = cur;
        }

        return nums;
    }

    public int[] bubbleSort(int[] nums){
        for(int i = nums.length - 1; i > 0; i--) {
            for(int j = 0; j < i; j++) {
                if(nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        return nums;
    }
}