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
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        // Collections.sort(sortedElements1);
        return merge(sortBST(root1, new ArrayList<>()), sortBST(root2, new ArrayList<>()));
    }

    private List<Integer> merge(List<Integer> sortedElements1, List<Integer> sortedElements2) {
        int len1 = sortedElements1.size();
        int len2 = sortedElements2.size();
        List<Integer> res = new ArrayList<>(len1 + len2);
        int i = 0;
        int j = 0;
        while(i < len1 && j < len2) {
            if(sortedElements1.get(i) < sortedElements2.get(j)) {
                res.add(sortedElements1.get(i));
                i++;
            } else {
                res.add(sortedElements2.get(j));
                j++;
            }
        }
        while(i < len1) {
            res.add(sortedElements1.get(i));
            i++;
        }
        while(j < len2) {
            res.add(sortedElements2.get(j));
            j++;
        }

        return res;
    }

    private List<Integer> sortBST(TreeNode root, List<Integer> sortedElements) {
        if(root != null) {
            sortBST(root.left, sortedElements);
            sortedElements.add(root.val);
            sortBST(root.right, sortedElements);
        }
        return sortedElements;
    }
}