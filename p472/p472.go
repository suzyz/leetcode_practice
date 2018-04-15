package p472

import "sort"

type node struct {
	isWord bool
	p      [26]*node
}

type trie struct {
	root *node
}

func (t *trie) insert(s string) {
	cur := t.root
	for _, c := range s {
		if cur.p[c-'a'] == nil {
			cur.p[c-'a'] = &node{}
		}
		cur = cur.p[c-'a']
	}
	cur.isWord = true
}

func findAllConcatenatedWordsInADict(words []string) []string {
	t := &trie{
		root: &node{},
	}
	m := make(map[string]bool)
	for _, w := range words {
		t.insert(w)
		m[w] = true
	}

	sort.Slice(words, func(i, j int) bool {
		return len(words[i]) < len(words[j])
	})

	ans := []string{}
	for _, w := range words {
		if isConcatenated(w, t, m) {
			ans = append(ans, w)
		}
	}
	return ans
}

func isConcatenated(w string, t *trie, m map[string]bool) bool {
	cur := t.root
	n := len(w)
	for i := 0; i < n-1; i++ {
		cur = cur.p[w[i]-'a']
		if cur == nil {
			return false
		}
		if cur.isWord {
			tail := w[i+1:]
			if m[tail] || isConcatenated(tail, t, m) {
				m[w] = true
				return true
			}
		}
	}
	return false
}
