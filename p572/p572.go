/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isIdenticalTree(s *TreeNode, t *TreeNode) bool {
	if s == nil && t == nil {
		return true
	}
	if s == nil || t == nil || s.Val != t.Val {
		return false
	}

	return isIdenticalTree(s.Left, t.Left) && isIdenticalTree(s.Right, t.Right)
}

func isSubtree(s *TreeNode, t *TreeNode) bool {
    if s == nil {
    	return t == nil
	}

	if t == nil {
		return false
	}

	if s.Val == t.Val && isIdenticalTree(s, t) {
		return true
	}

	if isSubtree(s.Left, t) || isSubtree(s.Right, t) {
		return true
	} else {
		return false
	}
}
