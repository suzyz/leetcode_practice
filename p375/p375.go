package p375

import "math"

func getMoneyAmount(n int) int {
	f := make([][]int, n+1)
	for i := 1; i <= n; i++ {
		f[i] = make([]int, n+1)
	}

	return dfs(1, n, f)
}

func abs(i int) int {
	if i < 0 {
		return -i
	} else {
		return i
	}
}
