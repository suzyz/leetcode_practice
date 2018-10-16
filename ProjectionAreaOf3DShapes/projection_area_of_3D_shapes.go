package p887

func projectionArea(grid [][]int) int {
	n, m := len(grid), len(grid[0])

	sum := 0
	for i := 0; i < n; i++ {
		max := 0
		for j := 0; j < m; j++ {
			if grid[i][j] > 0 {
				sum++

				if grid[i][j] > max {
					max = grid[i][j]
				}
			}
		}
		sum += max
	}

	for j := 0; j < m; j++ {
		max := 0
		for i := 0; i < n; i++ {
			if grid[i][j] > max {
				max = grid[i][j]
			}
		}
		sum += max
	}

	return sum
}
