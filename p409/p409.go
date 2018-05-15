package p409

func longestPalindrome(s string) int {
	m := make(map[byte]int)
	str := []byte(s)

	for _, c := range str {
		m[c]++
	}

	res := 0
	for _, v := range m {
		res += v / 2 * 2
	}

	if res < len(s) {
		res++
	}
	return res
}
