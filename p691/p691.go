// DP + Search.
// O((2^n)*m*(2^n)), n = len(target), m = len(stickers).
// Plain. Too slow.
package p691

func minStickers(stickers []string, target string) int {
	n := len(target)
	if n == 0 {
		return 0
	}
	m := len(stickers)
	set := make([]bool, 26)
	for i := 0; i < m; i++ {
		for _, c := range stickers[i] {
			set[c-'a'] = true
		}
	}
	for _, c := range target {
		if !set[c-'a'] {
			return -1
		}
	}

	tot := (1 << uint(n)) - 1
	f := make([]int, tot+1)
	f[0] = 0
	for i := 1; i <= tot; i++ {
		f[i] = n + 1
		for j := 0; j < m; j++ {
			lim := len(stickers[j]) - 1
			pos := make([]uint, 0)
			vis := make([]bool, lim+1)

			for k := n - 1; k >= 0; k-- {
				if ((1 << uint(k)) & i) == 0 {
					continue
				}

				for t := lim; t >= 0; t-- {
					if (!vis[t]) && stickers[j][t] == target[k] {
						pos = append(pos, uint(k))
						vis[t] = true
						break
					}
				}
			}

			if len(pos) == 0 {
				continue
			}
			if len(pos) == 1 {
				if f[i] > f[i-(1<<pos[0])]+1 {
					f[i] = f[i-(1<<pos[0])] + 1
				}
			} else {
				min := n + 1
				dfs(0, 0, pos, f, i, &min)
				min++
				if f[i] > min {
					f[i] = min
				}
			}
		}
	}

	if f[tot] == n+1 {
		return -1
	} else {
		return f[tot]
	}
}

func dfs(idx, status int, pos []uint, f []int, all int, min *int) {

	if idx >= len(pos) {
		if f[all-status] < *min {
			*min = f[all-status]
		}
		return
	}

	dfs(idx+1, status+(1<<pos[idx]), pos, f, all, min)
	dfs(idx+1, status, pos, f, all, min)
}
