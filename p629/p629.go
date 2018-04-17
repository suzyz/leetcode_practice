
func kInversePairs(n int, k int) int {
	if k == 0 || k == n*(n-1)/2 {
		return 1
	}

	if k > n*(n-1)/2 {
		return 0
	}

	const mo = 1e9 + 7

	f := make([][]int, n+1)
	f[1] = make([]int, k+1)
	f[1][0] = 1
	for i := 2; i <= n; i++ {
		f[i] = make([]int, k+1)
		f[i][0] = 1

		lim := i * (i - 1) / 2
        if lim > k {
            lim = k
        }
		for j := 1; j <= lim; j++ {
			// original:
			// f[i][j] = f[i-1][j] + f[i-1][j-1] + f[i-1][j-2] ... + f[i-1][j-(i-1)]

			f[i][j] = f[i][j-1] + f[i-1][j]
			if i <= j {
				f[i][j] -= f[i-1][j-i]
			}
			f[i][j] = (f[i][j] + mo) % mo
		}
	}

	return f[n][k]
}
