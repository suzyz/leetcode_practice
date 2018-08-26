package p

func surfaceArea(grid [][]int) int {
	n := len(grid)
	m := len(grid[0])

	res := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] > 0 {
				res += 2 // top & bottom

				for k := 1; k <= grid[i][j]; k++ {
					if i == n-1 || (i < n-1 && grid[i+1][j] < k) {
						res++ // front
					}
					if i == 0 || (i > 0 && grid[i-1][j] < k) {
						res++ // back
					}

					if j == m-1 || (j < m-1 && grid[i][j+1] < k) {
						res++ // right
					}

					if j == 0 || (j > 0 && grid[i][j-1] < k) {
						res++ // left
					}
				}
			}
		}
	}

	return res
}
