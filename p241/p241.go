package p241

import (
	"strconv"
)

func diffWaysToCompute(input string) []int {
	n := len(input)
	ans := make([]int, 0)
	isOperator := false

	for i := 0; i < n; i++ {
		if input[i] >= '0' && input[i] <= '9' {
			continue
		}
		isOperator = true

		p1 := diffWaysToCompute(input[:i])
		p2 := diffWaysToCompute(input[i+1:])

		for _, a := range p1 {
			for _, b := range p2 {
				switch input[i] {
				case '+':
					ans = append(ans, a+b)
				case '-':
					ans = append(ans, a-b)
				case '*':
					ans = append(ans, a*b)
				}
			}
		}
	}

	if !isOperator {
		d, _ := strconv.Atoi(input)
		ans = append(ans, d)
	}

	return ans
}
