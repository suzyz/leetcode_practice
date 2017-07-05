
class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val=x; }
}

public class p94 {
	public static void dfs(TreeNode root,List<Integer> ans)
	{
		if(root.left!=null) dfs(root.left,ans);
		ans.add(root.val);
		if(root.right!=null) dfs(root.right,ans);
	}
	public List<Integer> inorderTraversal(TreeNode root)
	{
		List<Integer> ans = new ArrayList<Integer>();
		if(root==null) return ans;
		dfs(root,ans);
		return ans;
	}
}