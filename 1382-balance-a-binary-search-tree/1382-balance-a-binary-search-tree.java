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
import java.util.*;

class Solution {

    List<Integer> list = new ArrayList<>();

    public TreeNode balanceBST(TreeNode root) {

        // Step 1: Store sorted values using inorder
        inorder(root);

        // Step 2: Build balanced BST
        return buildTree(0, list.size() - 1);
    }

    void inorder(TreeNode root) {

        if (root == null) {
            return;
        }

        inorder(root.left);

        list.add(root.val);

        inorder(root.right);
    }

    TreeNode buildTree(int left, int right) {

        if (left > right) {
            return null;
        }

        int mid = left + (right - left) / 2;

        TreeNode root = new TreeNode(list.get(mid));

        root.left = buildTree(left, mid - 1);

        root.right = buildTree(mid + 1, right);

        return root;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna