// Regular DP, without optimization.
func maxProfit(prices []int, fee int) int {
    n := len(prices)
    if n < 2 {
    	return 0
    }

    f := make([]int, n)
    g := make([]int, n)

    f[0] = 0
    g[0] = -prices[0]

    for i := 1; i < n; i++ {
    	g[i] = max(f[i-1] - prices[i], g[i-1])
    	f[i] = max(g[i-1] + prices[i] - fee, f[i-1])
    }

    return f[n-1]
}

func max(a,b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}