func longestSubstring(s string, k int) int {
	if len(s) < k {
		return 0
	}

	freq := make(map[rune]int)
	for _, ch := range []rune(s) {
		freq[ch]++
	}

	minf := k
	minch := 'a'

	for ch := 'a'; ch <= 'z'; ch++ {
		if freq[ch] == 0 || freq[ch] >= k {
			continue
		}

		if freq[ch] < minf {
			minf = freq[ch]
			minch = ch
		}
	}

	if minf == k {
		return len(s)
	}

	substrs := strings.Split(s, string(minch))
	res := 0
	for _, sub := range substrs {
		tmp := longestSubstring(sub, k)
		if tmp > res {
			res = tmp
		}
	}
	return res
}