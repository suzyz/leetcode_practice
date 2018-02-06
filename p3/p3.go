func lengthOfLongestSubstring(s string) int {
	m := make(map[byte]int)

	st := 0
	maxlen := 0
	for i, ch := range []byte(s) {
	   	if last, ok := m[ch]; ok && last >= st {
	   		st = last + 1
	   	}
	   	if i - st + 1 > maxlen {
	   		maxlen = i - st + 1
	   	}

	   	m[ch] = i
	}

	return maxlen
}