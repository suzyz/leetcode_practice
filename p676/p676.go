package p676

const maxSize = 26

type node struct {
	next   [maxSize]*node
	isWord bool
}

type MagicDictionary struct {
	root *node
}

/** Initialize your data structure here. */
func Constructor() MagicDictionary {
	m := MagicDictionary{}
	m.root = &node{}
	return m
}

/** Build a dictionary through a list of words */
func (this *MagicDictionary) BuildDict(dict []string) {
	for _, w := range dict {
		this.insert(w)
	}
}

/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
func (this *MagicDictionary) Search(word string) bool {
	return searchWithMagic(this.root, 0, word, false)
}

func searchWithMagic(p *node, idx int, w string, modification bool) bool {
	if p == nil {
		return modification && idx == len(w)
	}

	if idx == len(w) {
		return modification && p.isWord
	}

	if modification {
		if p.next[w[idx]-'a'] == nil {
			return false
		} else {
			return searchWithMagic(p.next[w[idx]-'a'], idx+1, w, true)
		}
	} else {
		for i := 0; i < maxSize; i++ {
			if p.next[i] != nil {
				if i == int(w[idx]-'a') {
					if searchWithMagic(p.next[i], idx+1, w, false) {
						return true
					}
				} else {
					if searchWithMagic(p.next[i], idx+1, w, true) {
						return true
					}
				}
			}
		}
	}

	return false
}

func (this *MagicDictionary) insert(w string) {
	p := this.root
	for _, c := range w {
		if p.next[c-'a'] == nil {
			p.next[c-'a'] = &node{}
		}

		p = p.next[c-'a']
	}

	p.isWord = true
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.BuildDict(dict);
 * param_2 := obj.Search(word);
 */
