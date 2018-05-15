package p575

func distributeCandies(candies []int) int {
	n := len(candies)

	m := make(map[int]bool)
	for _, c := range candies {
		if _, ok := m[c]; !ok {
			m[c] = true
		}
	}

	if len(m) < n/2 {
		return len(m)
	} else {
		return n / 2
	}
}
