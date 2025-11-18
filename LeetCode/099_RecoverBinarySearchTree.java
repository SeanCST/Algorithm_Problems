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
    public void recoverTree(TreeNode root) {
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode node = root, x = null, y = null, pred = null;
        
        while (!stack.isEmpty() || root != null) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }

            root = stack.pop();
            if (pred != null && root.val < pred.val) {
                y = root;
                if (x == null) {
                    x = pred;
                } else {
                    break;
                }
            }
            pred = root;
            root = root.right;
        }

        int temp = x.val;
        x.val = y.val;
        y.val = temp;
    }
}


//  class Solution {

//     public void recoverTree(TreeNode root) {
//         List<TreeNode> list = new ArrayList<>();

//         inOrder(root, list);

//         int index1 = -1, index2 = -1;
//         for (int i = 0; i < list.size() - 1; i++) {
//             if (list.get(i).val > list.get(i + 1).val) {
//                 index2 = i + 1;
//                 if (index1 == -1) {
//                     index1 = i;
//                 } else {
//                     break;
//                 }
//             }
//         }

//         int temp = list.get(index1).val;
//         list.get(index1).val = list.get(index2).val;
//         list.get(index2).val = temp;
//     }

//     private void inOrder(TreeNode node, List<TreeNode> list) {
//         if (node == null) {
//             return;
//         }
//         inOrder(node.left, list);
//         list.add(node);
//         inOrder(node.right, list);
//     }
// }