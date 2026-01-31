class Solution {
    public int findKthLargest(int[] nums, int k) {
        return quickSelect(nums, 0, nums.length - 1, nums.length - k);
    }

    private int quickSelect(int[] nums, int l, int r, int target) {
        int pivotIndex = partition(nums, l, r);

        if (pivotIndex == target) {
            return nums[pivotIndex];
        } else if (pivotIndex > target) {
            return quickSelect(nums, l, pivotIndex - 1, target);
        } else {
            return quickSelect(nums, pivotIndex + 1, r, target);
        }
    }

    private int partition(int[] nums, int l, int r) {
        int pivot = nums[r];

        // [l, i-1] : < pivot
        // [i, j-1] : >= pivot
        // [j, r-1] : unprocessed
        // pivot : nums[r]
        int i = l;
        for (int j = l; j < r; j++) {
            if (nums[j] < pivot) {
                swap(nums, i, j);
                i++;
            }
        }

        swap(nums, i, r);

        return i;
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

// class Solution {
//     public int findKthLargest(int[] nums, int k) {
//         PriorityQueue<Integer> pq = new PriorityQueue<>(k + 1);

//         for (int num : nums) {
//             if (pq.size() < k || pq.peek() < num) {
//                 pq.add(num);
//             }

//             if (pq.size() > k) {
//                 pq.poll();
//             }
//         }

//         return pq.peek();
//     }
// }