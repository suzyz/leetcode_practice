package p316

func removeDuplicateLetters(s string) string {
	n := len(s)

	st := []byte{}
	count := make(map[byte]int)
	used := make(map[byte]bool)

	for i := 0; i < n; i++ {
		count[s[i]]++
	}

	for i := 0; i < n; i++ {
		count[s[i]]--

		if used[s[i]] {
			continue
		}

		for len(st) > 0 && st[len(st)-1] > s[i] && count[st[len(st)-1]] > 0 {
			used[st[len(st)-1]] = false
			st = st[:len(st)-1]
		}

		used[s[i]] = true
		st = append(st, s[i])
	}

	return string(st)
}
