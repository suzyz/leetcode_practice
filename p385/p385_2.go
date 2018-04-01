// Recursion

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
	if s[0] != '[' {
		tmp, _ := strconv.ParseInt(s, 10, 64)
		cur := &NestedInteger{}
		cur.SetInteger(int(tmp))
		return cur
	}

	if n == 2 {
		return &NestedInteger{}
	}

	res := &NestedInteger{}
	lastComma := -1
	level := 0
	s = s[1:n-1] + ","
	n--

	for i := 0; i < n; i++ {
		c := s[i]
		if c == ','{
			if level == 0 {
				cur := deserialize(s[lastComma+1:i])
				res.Add(*cur)

				lastComma = i
			}
		} else if c == '[' {
			level++
		} else if c == ']' {
			level--
		}
	}

	return res
}
