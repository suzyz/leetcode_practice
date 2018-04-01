// O(n^2). 2-dimensional LIS.
package p354

import "sort"

func maxEnvelopes(envelopes [][]int) int {
	n := len(envelopes)
	if n < 2 {
		return n
	}

	sort.Slice(envelopes, func(i, j int) bool {
		if envelopes[i][0] < envelopes[j][0] {
			return true
		} else if envelopes[i][0] > envelopes[j][0] {
			return false
		} else {
			return envelopes[i][1] < envelopes[j][1]
		}
	})

	maxv := 1
	f := make([]int, n)
	for i := 0; i < n; i++ {
		f[i] = 1
		for j := i - 1; j >= 0; j-- {
			if envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1] && f[j]+1 > f[i] {
				f[i] = f[j] + 1
			}
		}
		if f[i] > maxv {
			maxv = f[i]
		}
	}

	return maxv
}
