package p332

import (
	"sort"
)

const start = "JFK"

func findItinerary(tickets [][]string) []string {

	idx := make(map[string]int)
	airport := make([]string, 0)

	nexts := make(map[int][]int)

	tot := 0
	for _, t := range tickets {
		u, v := t[0], t[1]
		if _, ok := idx[u]; !ok {
			idx[u] = tot
			airport = append(airport, u)
			tot++
		}
		if _, ok := idx[v]; !ok {
			idx[v] = tot
			airport = append(airport, v)
			tot++
		}

		nexts[idx[u]] = append(nexts[idx[u]], idx[v])
	}

	for i := 0; i < tot; i++ {
		if len(nexts[i]) > 1 {
			sort.Slice(nexts[i], func(j, k int) bool {
				return airport[nexts[i][j]] < airport[nexts[i][k]]
			})
		}
	}

	cur := []int{idx[start]}
	vis := make(map[int][]bool)
	for i := 0; i < tot; i++ {
		vis[i] = make([]bool, len(nexts[i]))
	}

	dfs(len(tickets), &cur, vis, nexts)

	ans := []string{}
	for _, c := range cur {
		ans = append(ans, airport[c])
	}
	return ans
}

func dfs(left int, cur *[]int, vis map[int][]bool, nexts map[int][]int) bool {

	if left == 0 {
		return true
	}

	u := (*cur)[len(*cur)-1]
	for i, v := range nexts[u] {
		if vis[u][i] {
			continue
		}

		*cur = append(*cur, v)
		vis[u][i] = true

		if dfs(left-1, cur, vis, nexts) {
			return true
		}

		*cur = (*cur)[:len(*cur)-1]
		vis[u][i] = false
	}
	return false
}
