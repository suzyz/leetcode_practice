// Plain recursion.

package main

import (
	"fmt"
	"strings"
)

func main() {
	// res := calculate(" 2-1 + 2 ")
	// res := calculate("(1 +(4+ 5+2)-3)+(6 +8   )")
	// res := calculate("1-(5)")
	// res := calculate("2 - (5-6)")
	res := calculate("2-(5-10+(222-11)-6)")
	// res := calculate("(5-10+(222-11)-6)") // should be 200

	fmt.Println("res:", res)
}

func calculate(s string) int {
	strs := strings.Split(s, " ")
	s = ""
	for _, str := range strs {
		s = s + str
	}

	return calc(s, false)
}

func calc(s string, reverse bool) (res int) {
	res = 0
	if len(s) == 0 {
		return
	}

	n := len(s)

	if s[0] != '(' {
		i, v := 0, 0

		for i < n && s[i] >= '0' && s[i] <= '9' {
			v = 10*v + int(s[i]) - '0'
			i++
		}

		if i == n {
			res = v
		} else {
			t := s[i+1:]

			if s[i] == '+' {
				if reverse {
					res = v - calc(t, !reverse)
				} else {
					res = v + calc(t, reverse)
				}
			} else {
				if reverse {
					res = v + calc(t, reverse)
				} else {
					res = v - calc(t, !reverse)
				}
			}
		}

	} else { // s[0] == '('
		count, i := 1, 1
		for i = 1; i < n; i++ {
			if s[i] == ')' {
				count--
				if count == 0 {
					break
				}
			} else if s[i] == '(' {
				count++
			}
		}

		if i == n-1 {
			t := s[1 : n-1]
			res = calc(t, false)
		} else {
			t1 := s[1:i]
			t2 := s[i+2:]
			if s[i+1] == '+' {
				if reverse {
					res = calc(t1, false) - calc(t2, !reverse)
				} else {
					res = calc(t1, false) + calc(t2, reverse)
				}
			} else {
				if reverse {
					res = calc(t1, false) + calc(t2, reverse)
				} else {
					res = calc(t1, false) - calc(t2, !reverse)
				}
			}
		}
	}

	fmt.Println(s, "=", res, "reverse:", reverse)
	return
}
