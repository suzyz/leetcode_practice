// DP with space optimization.
func maxProfit(prices []int, fee int) int {
    n := len(prices)
    if n < 2 {
    	return 0
    }

    sold := 0
    bought := -prices[0]
    lastBought := bought

    for i := 1; i < n; i++ {
        lastBought = bought
    	bought = max(sold - prices[i], bought)
    	sold = max(lastBought + prices[i] - fee, sold)
    }

    return sold
}

func max(a,b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}