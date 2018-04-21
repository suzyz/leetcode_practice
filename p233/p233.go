package p233

func countDigitOne(n int) int {
	if n <= 0 {
		return 0
	}

	digits := make([]int, 0)
	tmp := n
	for tmp > 0 {
		digits = append([]int{tmp % 10}, digits...)
		tmp /= 10
	}

	l := len(digits)
	if l == 1 {
		return 1
	}

	fac := make([]int, l)
	fac[0] = 1
	for i := 1; i < l; i++ {
		fac[i] = fac[i-1] * 10
	}

	// Consider last l-1 digits.
	// Each time, set a digit as 1, and
	// the first digit varies in [0,...,digits[0]-1],    -> *digits[0]
	// the other digits vary in [0,...,9].               -> *fac[l-2]
	ans := (l - 1) * fac[l-2] * digits[0]

	// Now consider the first digit.
	if digits[0] == 1 {
		ans += n - fac[l-1] + 1
	} else {
		ans += fac[l-1]
	}
	ans += countDigitOne(n - digits[0]*fac[l-1])

	return ans
}
