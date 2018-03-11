func lastRemaining(n int) int {
    return helper(n, true)
}

func helper(n int, isLeft bool) int {
	if n < 2 {
		return n
	}

	if (!isLeft) && (n%2 == 0) {
		return 2 * helper(n/2, !isLeft) - 1
	} else {
		return 2 * helper(n/2, !isLeft)
	}
}
