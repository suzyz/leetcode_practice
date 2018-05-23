package p677

const maxSize = 'z' - '0'

type node struct {
	next [maxSize]*node
	v    int
}

type MapSum struct {
	root *node
}

/** Initialize your data structure here. */
func Constructor() MapSum {
	m := MapSum{}
	m.root = &node{}
	return m
}

func (this *MapSum) Insert(key string, val int) {
	p := this.root
	for _, c := range key {
		idx := c - '0'
		if p.next[idx] == nil {
			p.next[idx] = &node{}
		}

		p = p.next[idx]
	}

	p.v = val
}

func (this *MapSum) Sum(prefix string) int {
	p := this.root
	for _, c := range prefix {
		idx := c - '0'
		if p.next[idx] == nil {
			return 0
		}

		p = p.next[idx]
	}

	return dfs(p)
}

func dfs(p *node) int {
	res := p.v
	for i := 0; i < maxSize; i++ {
		if p.next[i] != nil {
			res += dfs(p.next[i])
		}
	}
	return res
}

/**
 * Your MapSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(key,val);
 * param_2 := obj.Sum(prefix);
 */
