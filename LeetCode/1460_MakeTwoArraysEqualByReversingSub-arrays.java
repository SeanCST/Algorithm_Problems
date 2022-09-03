class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        // Arrays.sort(target);
        // Arrays.sort(arr);

        // return Arrays.equals(target, arr);

        int[] num = new int[1001];
        for(int i = 0; i < target.length; i++){
            num[target[i]]++;
            num[arr[i]]--;
        }
        for(int i : num) {
            if(i != 0) 
                return false;
        }
        return true;
    }
}