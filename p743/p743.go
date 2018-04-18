package p743

const maxint = 600002

func networkDelayTime(times [][]int, N int, K int) int {

	g := make([][]int, N)
	for i := 0; i < N; i++ {
		g[i] = make([]int, N)
		for j := 0; j < N; j++ {
			if i != j {
				g[i][j] = maxint
			}
		}
	}

	for _, edge := range times {
		u, v, w := edge[0], edge[1], edge[2]
		u--
		v--
		if g[u][v] > w {
			g[u][v] = w
		}
	}

	dist := make([]int, N)
	copy(dist, g[K-1])

	vis := make([]bool, N)
	vis[K-1] = true

	for i := 1; i < N; i++ {
		mind := maxint
		idx := 0
		for j := 0; j < N; j++ {
			if dist[j] < mind && (!vis[j]) {
				mind = dist[j]
				idx = j
			}
		}

		if mind == maxint {
			break
		}

		vis[idx] = true

		for j := 0; j < N; j++ {
			if (!vis[j]) && dist[j] > mind+g[idx][j] {
				dist[j] = mind + g[idx][j]
			}
		}
	}

	maxd := 0
	for i := 0; i < N; i++ {
		if dist[i] == maxint {
			return -1
		}

		if dist[i] > maxd {
			maxd = dist[i]
		}
	}
	return maxd
}
