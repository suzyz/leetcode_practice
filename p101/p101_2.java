
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class p101_2 {
    public boolean isSymmetric(TreeNode root) {
        if(root==null) return true;
        if(root.left==null && root.right==null) return true;
        if(root.left==null || root.right==null) return false;
        
        Queue<TreeNode> q1=new LinkedList<TreeNode>();
        Queue<TreeNode> q2=new LinkedList<TreeNode>();

        TreeNode tmp1,tmp2;
        q1.offer(root.left);
        q2.offer(root.right);
        while(q1.size()>0 && q2.size()>0)
        {
            tmp1=q1.poll();
            tmp2=q2.poll();
            if(tmp1==null && tmp2==null) continue;
            if(tmp1==null || tmp2==null) return false;
            if(tmp1.val!=tmp2.val) return false;
            q1.offer(tmp1.left);
            q1.offer(tmp1.right);
            q2.offer(tmp2.right);
            q2.offer(tmp2.left);
        }
        if(q1.size()>0 || q2.size()>0) return false;
        return true;
    }
}
