package p216

func combinationSum3(k int, n int) [][]int {
	var ans [][]int
	if n <= 0 || n > 45 || k > 9 {
		return ans
	}

	cur := make([]int, 0)
	dfs(0, k, n, cur, &ans)

	return ans
}

func dfs(last, k, n int, cur []int, ans *[][]int) {
	if n == 0 && k == 0 {
		tmp := make([]int, len(cur))
		copy(tmp, cur)
		*ans = append(*ans, tmp)
	}

	if k == 0 || n == 0 {
		return
	}

	for i := last + 1; i < 10 && i <= n; i++ {
		cur = append(cur, i)
		dfs(i, k-1, n-i, cur, ans)
		cur = cur[:len(cur)-1]
	}
}
