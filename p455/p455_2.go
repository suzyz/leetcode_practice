package p455

func findContentChildren(g []int, s []int) int {
	n, m := len(g), len(s)
	sort.Slice(g, func(i, j int) bool {
		return g[i] < g[j]
	})

	sort.Slice(s, func(i, j int) bool {
		return s[i] < s[j]
	})

	res := 0
	for j := 0; j < m; j++ {
		if res < n && g[res] <= s[j] {
			res++
		}
	}

	return res
}
