package p832

func flipAndInvertImage(A [][]int) [][]int {
	n := len(A)
	for i := 0; i < n; i++ {
		m := len(A[i])
		for j := 0; 2*j < m-1; j++ {
			A[i][j], A[i][m-1-j] = A[i][m-1-j], A[i][j]
		}
		for j := 0; j < m; j++ {
			A[i][j] = 1 - A[i][j]
		}
	}
	return A
}
