package p375

const maxint = (1 << 31) - 1

func getMoneyAmount(n int) int {
	f := make([][]int, n+1)
	for i := 1; i <= n; i++ {
		f[i] = make([]int, n+1)
	}

	return dfs(1, n, f)
}

func dfs(l, r int, f [][]int) int {
	if l >= r {
		return 0
	}

	if f[l][r] > 0 {
		return f[l][r]
	}

	if l+1 == r {
		f[l][r] = l
		return l
	}

	f[l][r] = maxint
	for k := l; k <= r; k++ {
		localMax := k + max(dfs(l, k-1, f), dfs(k+1, r, f))
		f[l][r] = min(f[l][r], localMax)
	}
	return f[l][r]
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
