package p435

func eraseOverlapIntervals(intervals []Interval) int {

	n := len(intervals)
	if n < 2 {
		return 0
	}

	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i].Start < intervals[j].Start
	})

	f, maxf := make([]int, n), 1
	f[0] = 1
	for i := 1; i < n; i++ {
		f[i] = 1
		for j := i - 1; j >= 0; j-- {
			if intervals[j].End <= intervals[i].Start {
				f[i] = f[j] + 1
				break
			}
		}
		if f[i] > maxf {
			maxf = f[i]
		}
	}
	// fmt.Println(f)
	return n - maxf
}
