// Trie. O(N^2)

// package p745

type Node struct {
	wordIdx []int
	next    [26]*Node
}

type Trie struct {
	root Node
}

type WordFilter struct {
	prefixTrie Trie
	suffixTrie Trie
	words      []string
}

func (t *Trie) insert(w []byte, idx int) {
	p := &t.root
	p.wordIdx = append(p.wordIdx, idx)
	
	for _, c := range w {
		if p.next[c-'a'] == nil {
			p.next[c-'a'] = &Node{}
		}
		p = p.next[c-'a']
		p.wordIdx = append(p.wordIdx, idx)
	}
}

func (t *Trie) search(w []byte) []int {
	p := &t.root
	for _, c := range w {
		if p.next[c-'a'] == nil {
			return []int{}
		}
		p = p.next[c-'a']
	}

	return p.wordIdx
}

func reverse(w []byte) []byte {
	res := make([]byte, len(w))
	n := len(w)
	for i := 0; i < n; i++ {
		res[i] = w[n-1-i]
	}
	return res
}

func Constructor(words []string) WordFilter {
	wordFilter := WordFilter{
		prefixTrie: Trie{},
		suffixTrie: Trie{},
		words:      words,
	}

	for i, w := range words {
		b := []byte(w)
		wordFilter.prefixTrie.insert(b, i)
		wordFilter.suffixTrie.insert(reverse(b), i)
	}
	return wordFilter
}

func (this *WordFilter) F(prefix string, suffix string) int {
	r1 := this.prefixTrie.search([]byte(prefix))
	if len(r1) == 0 {
		return -1
	}
	r2 := this.suffixTrie.search(reverse([]byte(suffix)))
	if len(r2) == 0 {
		return -1
	}
	i, j := len(r1)-1, len(r2)-1
	for i >= 0 && j >= 0 {
		if r1[i] == r2[j] {
			return r1[i]
		}
		if r1[i] > r2[j] {
			i--
		} else {
			j--
		}
	}
	return -1
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * obj := Constructor(words);
 * param_1 := obj.F(prefix,suffix);
 */
