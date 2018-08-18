package p868

func binaryGap(N int) int {
	last, i, maxGap := -1, 0, 0

	for N > 0 {

		if (N & 1) == 1 {
			if last >= 0 && i-last > maxGap {
				maxGap = i - last
			}
			last = i
		}

		N >>= 1
		i++
	}

	return maxGap
}
