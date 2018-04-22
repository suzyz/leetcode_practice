package p211

type node struct {
	isWord bool
	nexts  [26]*node
}

type WordDictionary struct {
	root *node
}

/** Initialize your data structure here. */
func Constructor() WordDictionary {
	return WordDictionary{
		root: &node{},
	}
}

/** Adds a word into the data structure. */
func (this *WordDictionary) AddWord(word string) {
	p := this.root
	for _, c := range word {
		if p.nexts[c-'a'] == nil {
			p.nexts[c-'a'] = &node{}
		}
		p = p.nexts[c-'a']
	}
	p.isWord = true
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
func (this *WordDictionary) Search(word string) bool {
	return SearchHelper(word, this.root)
}

func SearchHelper(word string, p *node) bool {
	for i, c := range word {
		if c == '.' {

			t := word[i+1:]
			for j := 0; j < 26; j++ {
				if p.nexts[j] != nil && SearchHelper(t, p.nexts[j]) {
					return true
				}
			}
			return false

		} else {
			if p.nexts[c-'a'] == nil {
				return false
			}
			p = p.nexts[c-'a']
		}
	}
	return p.isWord
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddWord(word);
 * param_2 := obj.Search(word);
 */
