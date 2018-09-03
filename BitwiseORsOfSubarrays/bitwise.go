package p3

func subarrayBitwiseORs(A []int) int {
	n := len(A)

	m1 := make(map[int]bool)
	res := make(map[int]bool)

	for i := 0; i < n; i++ {
		m2 := make(map[int]bool)
		m2[A[i]] = true
		for k := range m1 {
			m2[k|A[i]] = true
		}

		for k := range m2 {
			res[k] = true
		}

		m1 = m2
	}

	return len(res)
}
