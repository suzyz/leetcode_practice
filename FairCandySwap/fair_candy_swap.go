package pFairCandySwap

func fairCandySwap(A []int, B []int) []int {
	s1, s2 := 0, 0
	m := make(map[int]bool)

	for _, v := range A {
		s1 += v
		m[v<<1] = true
	}

	for _, v := range B {
		s2 += v
	}

	diff := s1 - s2
	for _, v := range B {
		if m[2*v+diff] {
			return []int{(2*v + diff) >> 1, v}
		}
	}

	return []int{0, 0}
}
