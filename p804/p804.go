package p804

func uniqueMorseRepresentations(words []string) int {
	m, res := make(map[string]bool), 0

	code := [26]string{".-", "-...", "-.-.", "-..", ".", "..-.",
		"--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
		"---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
		".--", "-..-", "-.--", "--.."}

	for _, w := range words {
		s := ""
		for _, c := range w {
			s += code[c-'a']
		}
		if m[s] == false {
			res++
			m[s] = true
		}
	}
	return res
}
