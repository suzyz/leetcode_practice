package p451

func frequencySort(s string) string {
	n := len(s)
	buckets := make([][]byte, n+1)
	for i := 1; i <= n; i++ {
		buckets[i] = make([]byte, 0)
	}

	m := make(map[byte]int)
	for _, c := range s {
		m[byte(c)]++
	}

	for k, v := range m {
		buckets[v] = append(buckets[v], k)
	}

	res := make([]byte, 0)
	for i := n; i > 0; i-- {
		for _, c := range buckets[i] {
			for j := 0; j < i; j++ {
				res = append(res, c)
			}
		}
	}
	return string(res)
}
