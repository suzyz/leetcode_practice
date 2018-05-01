// O(N^2) DP.
// Using map.
package p446

func numberOfArithmeticSlices(A []int) int {
	n := len(A)
	m := make([]map[int]int, n)
	for i := 0; i < n; i++ {
		m[i] = make(map[int]int, n)
	}

	res := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			diff := A[j] - A[i]

			res += m[i][diff]

			m[j][diff] += m[i][diff] + 1
		}
	}

	return res
}
