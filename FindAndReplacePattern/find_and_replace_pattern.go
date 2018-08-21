package pFindAndReplacePattern

func findAndReplacePattern(words []string, pattern string) []string {
	res := []string{}

	for _, w := range words {
		if check(w, pattern) {
			res = append(res, w)
		}
	}

	return res
}

func check(w, pattern string) bool {
	m1 := make(map[byte]byte)
	m2 := make(map[byte]byte)

	for i := 0; i < len(w); i++ {
		if p, ok := m1[w[i]]; ok {
			if p != pattern[i] {
				return false
			}
		} else {
			if back, ok := m2[pattern[i]]; ok {
				if back != w[i] {
					return false
				}
			}
		}

		m1[w[i]] = pattern[i]
		m2[pattern[i]] = w[i]
	}

	return true
}
