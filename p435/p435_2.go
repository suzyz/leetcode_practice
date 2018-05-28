package p435

type Interval struct {
	Start int
	End   int
}

func eraseOverlapIntervals(intervals []Interval) int {

	n := len(intervals)
	if n < 2 {
		return 0
	}

	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i].End < intervals[j].End
	})

	end, maxlen := intervals[0].End, 1
	for i := 1; i < n; i++ {
		if intervals[i].Start >= end {
			maxlen++
			end = intervals[i].End
		}
	}

	return n - maxlen
}
