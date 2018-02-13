func longestValidParentheses(s string) int {
	var q []int
	ans := 0
	str := []byte(s)

	for i,c := range str {
		if c == '(' {
			q = append(q, i)
		} else {
			if len(q) > 0 && str[q[len(q)-1]] == '(' {
				q = q[0:len(q) - 1]
			} else {
				q = append(q, i)
			}
		}
	}
    
    if len(q) == 0 {
        return len(s)
    }

	q = append(q, len(s))
	for i := len(q) - 2; i >= 0; i-- {
		cur := q[i+1] - 1 - q[i]
		if cur > ans {
			ans = cur
		}
	}
    
    if q[0] > ans {
        ans = q[0]
    }

	return ans
}