package p318

func maxProduct(words []string) int {
	n := len(words)
	letters := make([]int, n)

	for i, w := range words {
		for _, c := range w {
			letters[i] |= 1 << uint(c-'a')
		}
	}

	res := 0
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			if letters[i]&letters[j] == 0 {
				if len(words[i])*len(words[j]) > res {
					res = len(words[i]) * len(words[j])
				}
			}
		}
	}
	return res
}
