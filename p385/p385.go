// Iteration.

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * type NestedInteger struct {
 * }
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * func (n NestedInteger) IsInteger() bool {}
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * // So before calling this method, you should have a check
 * func (n NestedInteger) GetInteger() int {}
 *
 * // Set this NestedInteger to hold a single integer.
 * func (n *NestedInteger) SetInteger(value int) {}
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 * func (n *NestedInteger) Add(elem NestedInteger) {}
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The list length is zero if this NestedInteger holds a single integer
 * // You can access NestedInteger's List element directly if you want to modify it
 * func (n NestedInteger) GetList() []*NestedInteger {}
 */


func deserialize(s string) *NestedInteger {
	n := len(s)

	if n == 0 {
		return &NestedInteger{}
	}
	if s[0] == '-' || (s[0] >= '0' && s[0] <= '9') {
		tmp, _ := strconv.ParseInt(s, 10, 64)
		cur := &NestedInteger{}
		cur.SetInteger(int(tmp))
		return cur
	}

	cur := &NestedInteger{}
	st := make([]*NestedInteger, 0) // stack

	l, r := 1, 1
	for i := 1; i < n; i++ {
		c := s[i]
		switch {
		case c == '-' || (c >= '0' && c <= '9'):
			r++
		case c == ',':
			if s[i-1] == ']' {
                l = i + 1
			    r = l
				continue
			}
			tmp, _ := strconv.ParseInt(s[l:r], 10, 64)
			k := &NestedInteger{}
			k.SetInteger(int(tmp))
			cur.Add(*k)
			l = i + 1
			r = l
		case c == '[':
			st = append(st, cur)
			cur = &NestedInteger{}
			l = i + 1
			r = l
		case c == ']':
			if l < r {
				tmp, _ := strconv.ParseInt(s[l:r], 10, 64)
				k := &NestedInteger{}
				k.SetInteger(int(tmp))
				cur.Add(*k)
			}

			if len(st) > 0 {
				backup := cur
				cur = st[len(st)-1]
				st = st[:len(st)-1]
				cur.Add(*backup)
			}

			l = i + 1
			r = l
		}
	}

	return cur
}
