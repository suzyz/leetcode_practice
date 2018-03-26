// O(n).
func countBinarySubstrings(s string) int {
	n, ans := len(s), 0
	curLen, preLen := 1, 0

	for i := 1; i < n; i++ {
		if s[i] == s[i-1] {
			curLen++
		} else {
			ans += min(curLen, preLen)

			preLen = curLen
			curLen = 1
		}
	}
	ans += min(curLen, preLen)
    
    return ans
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}