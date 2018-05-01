package p345

func reverseVowels(s string) string {
	l, r := 0, len(s)-1
	b := []byte(s)
	isVowel := make(map[byte]bool)
	vowels := []byte{'a', 'e', 'i', 'o', 'u'}
	for _, v := range vowels {
		isVowel[v] = true
		isVowel[v-'a'+'A'] = true
	}

	for l < r {
		for l < r && !isVowel[b[l]] {
			l++
		}
		for l < r && !isVowel[b[r]] {
			r--
		}

		b[l], b[r] = b[r], b[l]
		l++
		r--
	}
	return string(b)
}
