// O(N^3) DP.
// f[j][k] : Number of arithmetic subsequences whose last two numbers are A[j] and A[k].
package p446

func numberOfArithmeticSlices(A []int) int {
	n := len(A)
	f := make([][]int, n)
	for i := 0; i < n-1; i++ {
		f[i] = make([]int, n)
	}

	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			diff := A[j] - A[i]
			for k := j + 1; k < n; k++ {
				if A[k]-A[j] == diff {
					f[j][k]++
				}
			}
		}
	}

	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			if f[i][j] == 0 {
				continue
			}

			diff := A[j] - A[i]
			for k := j + 1; k < n; k++ {
				if A[k]-A[j] == diff {
					f[j][k] += f[i][j]
				}
			}
		}
	}

	res := 0
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			res += f[i][j]
		}
	}
	return res
}
