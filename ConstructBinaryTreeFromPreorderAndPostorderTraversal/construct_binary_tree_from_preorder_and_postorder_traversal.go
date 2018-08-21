package pConstructFromPrePost

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func constructFromPrePost(pre []int, post []int) *TreeNode {

	n := len(pre)
	if n == 0 {
		return nil
	}
	root := &TreeNode{}

	root.Val = pre[0]
	if n == 1 {
		return root
	}

	lh := pre[1]
	i := 0
	for i < n-1 {
		if post[i] == lh {
			break
		}
		i++
	}

	root.Left = constructFromPrePost(pre[1:i+2], post[0:i+1])

	root.Right = constructFromPrePost(pre[i+2:n], post[i+1:n-1])

	return root
}
