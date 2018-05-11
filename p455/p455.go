package p455

func findContentChildren(g []int, s []int) int {
	n, m := len(g), len(s)
	sort.Slice(g, func(i, j int) bool {
		return g[i] < g[j]
	})

	sort.Slice(s, func(i, j int) bool {
		return s[i] < s[j]
	})

	j, res := 0, 0
	for i := 0; i < n; i++ {
		for j < m && g[i] > s[j] {
			j++
		}
		if j == m {
			break
		} else {
			res++
			j++
		}
	}

	return res
}
