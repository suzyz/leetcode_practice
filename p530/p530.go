package p530

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorderTraversal(cur *TreeNode, oldMinDiff int) (newMinDiff, first, last int) {
	if cur == nil {
		newMinDiff = oldMinDiff
		first = 1 << 20
		last = 1 << 20
		return
	}
	newMinDiff = oldMinDiff
	first = cur.Val
	last = cur.Val

	if cur.Left != nil {
		leftMinDiff, leftFirst, leftLast := inorderTraversal(cur.Left, oldMinDiff)
		first = leftFirst

		if leftMinDiff < newMinDiff {
			newMinDiff = leftMinDiff
		}

		if cur.Val-leftLast < newMinDiff {
			newMinDiff = cur.Val - leftLast
		}
	}

	if cur.Right != nil {
		rightMinDiff, rightFirst, rightLast := inorderTraversal(cur.Right, oldMinDiff)
		last = rightLast
		if rightMinDiff < newMinDiff {
			newMinDiff = rightMinDiff
		}

		if rightFirst-cur.Val < newMinDiff {
			newMinDiff = rightFirst - cur.Val
		}
	}
	// fmt.Println(cur.Val, last, newMinDiff)
	return
}

func getMinimumDifference(root *TreeNode) int {
	minDiff, _, _ := inorderTraversal(root, 1<<20)
	return minDiff
}
