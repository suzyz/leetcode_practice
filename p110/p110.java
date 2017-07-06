/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int getNum(TreeNode root)
    {
        if(root==null) return 0;
        if(root.right)
        return getNum(root.left)-getNum(root.right);
    }
    public boolean isBalanced(TreeNode root) {
        if(Math.abs(getNum(root))<2) return true;
        else return false;
    }
}
