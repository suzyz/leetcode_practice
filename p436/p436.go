//O(N^2). Brutal Force.
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
		k := i + 1

		for k < n && intervals[idx[k]].Start < intervals[idx[i]].End {
			k++
		}

		if k == n {
			res[idx[i]] = -1
		} else {
			res[idx[i]] = idx[k]
		}
	}
	return res
}
