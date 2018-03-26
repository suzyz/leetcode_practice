package p664

func strangePrinter(s string) int {
	n := len(s)
	if n < 2 {
		return n
	}
	f := make([][]int, n)
	for i := 0; i < n; i++ {
		f[i] = make([]int, n)
		f[i][i] = 1
	}

	for i := 2; i <= n; i++ {
		for st := 0; st <= n-i; st++ {
			en := st + i - 1
			f[st][en] = f[st+1][en] + 1
			for k := st; k < en; k++ {
				tmp := f[st][k] + f[k+1][en]
				if s[st] == s[k+1] {
					tmp--
				}
				f[st][en] = min(f[st][en], tmp)
			}
		}
	}

	return f[0][n-1]
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
