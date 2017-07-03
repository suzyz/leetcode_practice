
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class p101 {
    public boolean isMirror(TreeNode a,TreeNode b)
    {
        if(a==null && b==null) return true;
        if(a==null || b==null) return false;
        if(a.val!=b.val) return false;
        return isMirror(a.left,b.right)&&isMirror(a.right,b.left);
    }
    public boolean isSymmetric(TreeNode root) {
        if(root==null) return true;
        return isMirror(root.left,root.right);
    }
}
