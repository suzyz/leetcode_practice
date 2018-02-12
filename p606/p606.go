/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func tree2str(t *TreeNode) string {
    if t == nil {
    	return ""
    }

   	res := strconv.Itoa(t.Val)
   	if t.Left == nil && t.Right == nil {
   		return res
   	}

	res += "(" + tree2str(t.Left) + ")"

   	if t.Right != nil {
   		res += "(" + tree2str(t.Right) + ")"
   	}

   	return res
}
