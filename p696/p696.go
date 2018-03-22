// Brutal force. O(n^2).
func countBinarySubstrings(s string) int {
	n, ans := len(s), 0
	str := []byte(s)

	for i := 1; i < n; i++ {
		ans += helper('0', '1', i, n, str)
		ans += helper('1', '0', i, n, str)
	}
    
    return ans
}

func helper(k1, k2 byte, center, n int, str []byte) int {
	count := 0
	i, j := center-1, center

	for i >= 0 && j < n && str[i] == k1 && str[j] == k2 {
		i--
		j++
		count++
	}

	return count
}