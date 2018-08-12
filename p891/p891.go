package p891

func superEggDrop(K int, N int) int {

	f := make([][]int, N+1)
	for i := 0; i <= N; i++ {
		f[i] = make([]int, K+1)
	}

	i := 0
	for f[i][K] < N {
		i++

		for j := 1; j <= K; j++ {
			f[i][j] = f[i-1][j-1] + f[i-1][j] + 1
		}
	}

	return i
}
