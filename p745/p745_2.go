// Map. O(N)

package p745

type WordFilter struct {
	m map[string]int
}

func Constructor(words []string) WordFilter {
	m := make(map[string]int)

	for weight, s := range words {
		n := len(s)
		for i := 0; i <= n; i++ {
			for j := 0; j <= n; j++ {
				m[s[:i]+"#"+s[j:]] = weight
			}
		}
	}
	return WordFilter{m}
}

func (this *WordFilter) F(prefix string, suffix string) int {
	if w, ok := this.m[prefix+"#"+suffix]; ok {
		return w
	}
	return -1
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * obj := Constructor(words);
 * param_1 := obj.F(prefix,suffix);
 */
