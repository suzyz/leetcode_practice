// O(n*logn). 2-dimensional LIS.
// To prevent [2,3] include [2,2], we sort like this:
// Ascend on width and descend on height if width are same.
// Then [2,3] would be in front of [2,2].
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
			return envelopes[i][1] > envelopes[j][1] // Descending!!
		}
	})

	maxlen := 1
	f := make([]int, n)
	f[0] = 0
	for i := 1; i < n; i++ {

		pos := sort.Search(maxlen, func(idx int) bool {
			return envelopes[f[idx]][1] >= envelopes[i][1]
		})

		f[pos] = i
		if pos >= maxlen {
			maxlen++
		}
	}

	return maxlen
}
