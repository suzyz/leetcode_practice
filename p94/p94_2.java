
class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val=x; }
}
public class p94_2 {

	public List<Integer> inorderTraversal(TreeNode root){
		List<Integer> ans = new ArrayList<Integer>();
		if(root==null) return ans;

		Stack<TreeNode> st = new Stack<TreeNode>();

		TreeNode tmp=root;
		while(tmp!=null || !st.empty())
		{
			while(tmp!=null)
			{
				st.push(tmp);
				tmp=tmp.left;
			}

			tmp=st.pop();
			ans.add(tmp.val);
			tmp=tmp.right;
		}
		return ans;
	}
}