func lengthOfLongestSubstring(s string) int {
	m := make(map[byte]int) // 将byte改为rune可处理中文

	st := 0
	maxlen := 0
	for i, ch := range []byte(s) {  // 将byte改为rune可处理中文
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