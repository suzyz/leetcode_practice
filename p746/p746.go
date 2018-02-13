
func min2(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func minCostClimbingStairs(cost []int) int {
	n := len(cost)
	f := make([]int, n + 1)
	f[0] = 0
    f[1] = 0
	
    for i := 2; i <= n; i++ {
		f[i] = min2(f[i-2] + cost[i-2], f[i-1] + cost[i-1])
	}

	return f[n]   
}
