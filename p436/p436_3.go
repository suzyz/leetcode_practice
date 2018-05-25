// Theoretically, O(N*logN). Quick sort written by myself, plus binary Search.
// But actually, realy slow.
package p436

type Interval struct {
	Start int
	End   int
}

func qs(intervals []Interval, idx []int, l, r int) {
	if l >= r {
		return
	}

	k := l
	for i := l; i < r-1; i++ {
		if intervals[idx[i]].Start < intervals[idx[r-1]].Start ||
			(intervals[idx[i]].Start == intervals[idx[r-1]].Start && idx[i] < idx[r-1]) {
			idx[i], idx[k] = idx[k], idx[i]
			k++
		}
	}

	idx[r-1], idx[k] = idx[k], idx[r-1]

	qs(intervals, idx, l, k)
	qs(intervals, idx, k+1, r)
}

func findRightInterval(intervals []Interval) []int {
	n := len(intervals)

	idx := make([]int, n)
	for i := 0; i < n; i++ {
		idx[i] = i
	}

	qs(intervals, idx, 0, n)

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
