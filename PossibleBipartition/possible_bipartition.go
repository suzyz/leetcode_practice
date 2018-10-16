package p890

func possibleBipartition(N int, dislikes [][]int) bool {
	color := make([]int, N+1)
	g := make([][]bool, N+1)
	for i := 1; i <= N; i++ {
		g[i] = make([]bool, N+1)
	}

	for i := 0; i < len(dislikes); i++ {
		u, v := dislikes[i][0], dislikes[i][1]

		g[u][v] = true
		g[v][u] = true
	}

	for i := 1; i <= N; i++ {
		if color[i] == 0 {
			color[i] = 1
			if !dfs(i, g, &color) {
				return false
			}
		}
	}

	return true
}

func dfs(cur int, g [][]bool, color *[]int) bool {

	for i, v := range g[cur] {
		if v {
			if (*color)[i] == 0 {
				(*color)[i] = 3 - (*color)[cur]

				if !dfs(i, g, color) {
					return false
				}

			} else if (*color)[i] != 3-(*color)[cur] {
				return false
			}
		}
	}
	return true
}
