
func isBipartite(graph [][]int) bool {
	n := len(graph)

	color := make([]int, n)
	for i := 0; i < n; i++ {
		if color[i] == 0 {
			if !dfs(i, 1, color, graph) {
				return false
			}
		}
	}
	return true
}

func dfs(cur, co int, color []int, graph [][]int) bool {
	if color[cur] == co {
		return true
	}

	if color[cur] == -co {
		return false
	}

	color[cur] = co
	for _, v := range graph[cur] {
		if !dfs(v, -co, color, graph) {
			return false
		}
	}
	return true
}
