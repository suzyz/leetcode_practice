package p807

func maxIncreaseKeepingSkyline(grid [][]int) int {
	n, m := len(grid), len(grid[0]) // n, m > 1

	contourFromTop, contourFromLeft := make([]int, m), make([]int, n)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			contourFromLeft[i] = max(contourFromLeft[i], grid[i][j])
			contourFromTop[j] = max(contourFromTop[j], grid[i][j])
		}
	}

	res := 0

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			lim := min(contourFromLeft[i], contourFromTop[j])
			if grid[i][j] < lim {
				res += lim - grid[i][j]
			}
		}
	}

	return res
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
