package p2

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inOrder(cur *TreeNode, nums *[]int) {
	if cur == nil {
		return
	}
	inOrder(cur.Left, nums)

	*nums = append(*nums, cur.Val)

	inOrder(cur.Right, nums)
}

func increasingBST(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	nums := []int{}
	inOrder(root, &nums)

	dumbNewRoot := &TreeNode{}
	p := dumbNewRoot

	for _, v := range nums {
		p.Right = &TreeNode{}
		p.Right.Val = v

		p = p.Right
	}

	return dumbNewRoot.Right
}
