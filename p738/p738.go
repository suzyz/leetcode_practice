package p738

func monotoneIncreasingDigits(N int) int {
	if N < 10 {
		return N
	}

	digits := []int{}

	n := N
	for n > 0 {
		digits = append([]int{n % 10}, digits...)
		n /= 10
	}

	l := len(digits)
	ans := 0

	for i := 0; i < l-1; i++ {
		if digits[i] > digits[i+1] {
			digits[i]--
			for j := i + 1; j < l; j++ {
				digits[j] = 9
			}

			for i > 0 && digits[i] < digits[i-1] {
				digits[i-1]--
				digits[i] = 9

				i--
			}

			for j := 0; j < l; j++ {
				ans = 10*ans + digits[j]
			}
			return ans
		}
	}

	return N
}
