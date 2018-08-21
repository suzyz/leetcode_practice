package pSumSubseqWidths

import (
	"math"
	"sort"
)

func sumSubseqWidths(A []int) int {
	n := len(A)
	const mo = 1e9 + 7

	sort.Slice(A, func(i, j int) bool {
		return A[i] < A[j]
	})

	res := float64(0)

	fac := 1
	for i := 0; i < n; i++ {
		res = (res + fac*A[i] - fac*A[n-1-i]) % mo
		fac = (fac << 1) % mo
	}

	return res
}
