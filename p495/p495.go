package p495

func findPoisonedDuration(timeSeries []int, duration int) int {
	n, tot := len(timeSeries), 0
	if n == 0 {
		return 0
	}

	for i := 0; i < n-1; i++ {
		tot += min(timeSeries[i+1]-timeSeries[i], duration)
	}

	// The last one.
	tot += duration

	return tot
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
