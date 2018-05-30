package p797

func allPathsSourceTarget(graph [][]int) [][]int {
	n := len(graph)
	curPath, res := []int{0}, [][]int{}

	dfs(0, n-1, &curPath, &res, graph)
	return res
}

func dfs(cur, destination int, curPath *[]int, res *[][]int, graph [][]int) {
	if cur == destination {
		path := make([]int, len(*curPath))
		copy(path, *curPath)
		*res = append(*res, path) // careful
		return
	}

	for _, v := range graph[cur] {
		*curPath = append(*curPath, v)
		dfs(v, destination, curPath, res, graph)
		*curPath = (*curPath)[:len(*curPath)-1]
	}
}
