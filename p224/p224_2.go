// Handmade stack.

package main

import (
	"fmt"
	"strings"
)

type stack struct {
	expr []int
}

func (s *stack) push(v int) {
	s.expr = append(s.expr, v)
}

func (s *stack) pop() (v int) {
	if len(s.expr) == 0 {
		return 0
	}
	v = s.expr[len(s.expr)-1]
	s.expr = s.expr[:len(s.expr)-1]
	return
}

func main() {
	// res := calculate(" 2-1 + 2 ")
	// res := calculate("(1 +(4+ 5+2)-3)+(6 +8   )")
	// res := calculate("1-(5)")
	// res := calculate("2 - (5-6)")
	// res := calculate("2-(5-10+(222-11)-6)")
	res := calculate("(5-10+(222-11)-6)") // should be 200

	fmt.Println("res:", res)
}

func calculate(s string) int {
	strs := strings.Split(s, " ")
	s = "("
	for _, str := range strs {
		s = s + str
	}
	s += ")"
	n := len(s)

	st := &stack{}
	res, cur, sign := 0, 0, 1

	for i := 0; i < n; i++ {
		if s[i] == '+' {
			res += sign * cur
			sign = 1
			cur = 0
		} else if s[i] == '-' {
			res += sign * cur
			sign = -1
			cur = 0
		} else if s[i] == '(' {
			st.push(res)
			st.push(sign)

			cur, res = 0, 0
			sign = 1
		} else if s[i] == ')' {
			res += sign * cur

			cur = 0
			res *= st.pop()
			res += st.pop()
		} else {
			cur = 10*cur + int(s[i]) - '0'
		}

		// fmt.Println(i, byte(s[i]), "cur:", cur, "sign:", sign, "res:", res)
	}

	return res
}
