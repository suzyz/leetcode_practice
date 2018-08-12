// Space optimized.
package p891

func superEggDrop(K int, N int) int {

	f := make([]int, K+1)

	i := 0
	for f[K] < N {
		i++

		for j := K; j > 0; j-- {
			f[j] += f[j-1] + 1
		}
	}

	return i
}
