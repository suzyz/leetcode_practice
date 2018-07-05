package p554

func leastBricks(wall [][]int) int {
	m := make(map[int]int)
	height := len(wall)

	for i := 0; i < height; i++ {
		sum := 0
		l := len(wall[i])
		for j := 0; j < l-1; j++ {
			sum += wall[i][j]
			m[sum]++
		}
	}

	maxv := 0
	for _, v := range m {
		if v > maxv {
			maxv = v
		}
	}

	return height - maxv
}
