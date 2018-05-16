package p397

func integerReplacement(n int) int { // n is positive
	if n == 1 {
		return 0
	}

	if n&1 == 0 {
		return integerReplacement(n>>1) + 1
	} else {
		if n == 3 || countOnes(n+1) > countOnes(n-1) {
			return integerReplacement(n-1) + 1
		} else {
			return integerReplacement(n+1) + 1
		}
	}
}

func countOnes(i int) int {
	res := 0
	for i > 0 {
		res += (i & 1)
		i >>= 1
	}
	return res
}
