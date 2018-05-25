//O(N*logN). Binary Search.
package p436

type Interval struct {
	Start int
	End   int
}

func findRightInterval(intervals []Interval) []int {
	n := len(intervals)

	idx := make([]int, n)
	for i := 0; i < n; i++ {
		idx[i] = i
	}

	sort.Slice(idx, func(i, j int) bool {
		return intervals[idx[i]].Start < intervals[idx[j]].Start
	})

	res := make([]int, n)
	res[idx[n-1]] = -1

	for i := 0; i < n-1; i++ {
		target := intervals[idx[i]].End
		if intervals[idx[n-1]].Start < target {
			res[idx[i]] = -1
			continue
		}
		l, r := i+1, n-1

		for l < r {
			mid := l + ((r - l) >> 1)
			if intervals[idx[mid]].Start >= target {
				r = mid
			} else {
				l = mid + 1
			}
		}

		if l == n {
			res[idx[i]] = -1
		} else {
			res[idx[i]] = idx[l]
		}
	}
	return res
}
