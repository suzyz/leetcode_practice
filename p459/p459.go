package p459

func repeatedSubstringPattern(s string) bool {
	n := len(s)
	if n < 2 {
		return false
	}

	lim := n / 2
	for i := 1; i <= lim; i++ {
		if n%i == 0 {
			sub, j, flag := s[:i], 0, true
			for j < n {
				if sub != s[j:j+i] {
					flag = false
					break
				} else {
					j += i
				}
			}
			if flag {
				return true
			}
		}
	}

	return false
}
