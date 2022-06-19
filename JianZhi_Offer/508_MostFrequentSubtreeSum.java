/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private HashMap<Integer, Integer> map = new HashMap<>();
    private int maxFrequency = 0;

    public int[] findFrequentTreeSum(TreeNode root) {
        calculateTreeSum(root);
        ArrayList<Integer> res = new ArrayList<>();
        for(int key : map.keySet()) {
            if(map.get(key) == maxFrequency) {
                res.add(key);
            }
        }
        
        Integer[] resInteger = res.toArray(new Integer[res.size()]);
        return Arrays.stream(resInteger).mapToInt(Integer::valueOf).toArray();
    }

    private int calculateTreeSum(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int leftSum = calculateTreeSum(root.left);
        int rightSum = calculateTreeSum(root.right);
        int sum = leftSum + rightSum + root.val;

        if(map.containsKey(sum)) {
            int frequency = map.get(sum) + 1;
            map.put(sum, frequency);
        } else {
            map.put(sum, 1);
        }
        maxFrequency = maxFrequency > map.get(sum) ? maxFrequency : map.get(sum);


        return sum;
    }

}