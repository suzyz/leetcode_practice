
type NumMatrix struct {
	sum [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	res := NumMatrix{}
	n := len(matrix)
	res.sum = make([][]int, n+1)
	m := 0
	if n > 0 {
		m = len(matrix[0])
	}
    res.sum[0] = make([]int, m+1)
	for i := 1; i <= n; i++ {
		res.sum[i] = make([]int, m+1)
		col := 0
		for j := 1; j <= m; j++ {
			col += matrix[i-1][j-1]
			res.sum[i][j] = res.sum[i-1][j] + col
		}
	}
	return res
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	return this.sum[row2+1][col2+1] - this.sum[row1][col2+1] - this.sum[row2+1][col1] + this.sum[row1][col1]
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
