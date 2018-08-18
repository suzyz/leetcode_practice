package p866

import (
	"strconv"
)

func primePalindrome(N int) int {
	if N >= 8 && N <= 11 {
		return 11
	}

	const lim = 100000

	for i := 1; i < lim; i++ {
		s := strconv.Itoa(i)
		l := len(s)
		for j := l - 2; j >= 0; j-- {
			s += string(s[j])
		}

		v, _ := strconv.Atoi(s)
		if v >= N && isPrime(v) {
			return v
		}
	}

	return -1
}

func isPrime(v int) bool {
	if v < 2 || v%2 == 0 {
		return v == 2
	}

	for i := 3; i*i <= v; i += 2 {
		if v%i == 0 {
			return false
		}
	}
	return true
}
