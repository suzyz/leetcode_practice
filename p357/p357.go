package p357

func countNumbersWithUniqueDigits(n int) int {
	maxLength := n

	if maxLength > 10 {
		maxLength = 10
	}

	A10 := make([]int, 11)
	A9 := make([]int, 10)

	A10[0], A9[0] = 1, 1
	for i := 1; i <= maxLength; i++ {
		A10[i] = A10[i-1] * (10 - i + 1)
		if i <= 9 {
			A9[i] = A9[i-1] * (9 - i + 1)
		}
	}

	ans := 0
	for i := 0; i <= maxLength; i++ {
		ans += A10[i]
		if i > 0 {
			ans -= A9[i-1]
		}
	}
	return ans
}
