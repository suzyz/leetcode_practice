// without using slice

func longestValidParentheses(s string) int {
	q := make([]int,len(s) + 1)
	qlen := 0
	ans := 0
	str := []byte(s)

	for i,c := range str {
		if c == '(' {
			q[qlen] = i
			qlen++
		} else {
			if qlen > 0 && str[q[qlen-1]] == '(' {
				qlen--
			} else {
				q[qlen] = i
				qlen++
			}
		}
	}
    
    if qlen == 0 {
        return len(s)
    }

	q[qlen] = len(s)
	for i := qlen - 1; i >= 0; i-- {
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