package p396

func maxRotateFunction(A []int) int {
	n := len(A)
	if n < 2 {
		return 0
	}

	f := 0
	sum := make([]int, n)
	sum[0] = A[0]
	for i := 1; i < n; i++ {
		f += i * A[i]
		sum[i] = sum[i-1] + A[i]
	}

	maxf := f
	for i := 1; i < n; i++ {
		f += sum[n-1-i] + (sum[n-1] - sum[n-i]) - (n-1)*A[n-i]
		if f > maxf {
			maxf = f
		}
	}
	return maxf
}
