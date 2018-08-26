package AllPossibleFullBinaryTrees

func allPossibleFBT(N int) []*TreeNode {
	res := []*TreeNode{}

	if N%2 == 0 {
		return res
	}

	if N == 1 {
		r := &TreeNode{}
		r.Val = 0
		res = append(res, r)
		return res
	}

	for i := 1; i < N-1; i += 2 {
		lefts := allPossibleFBT(i)
		rights := allPossibleFBT(N - 1 - i)

		for _, l := range lefts {
			for _, r := range rights {
				root := &TreeNode{}
				root.Val = 0
				root.Left = l
				root.Right = r
				res = append(res, root)
			}
		}
	}

	return res
}
