package p306

func isAdditiveNumber(num string) bool {
	n := len(num)
	s := make([]int, n)
	for i := 0; i < n; i++ {
		s[i] = int(num[i]) - '0'
	}

	for i := 1; i < n-1; i++ {
		if s[0] == 0 && i > 1 {
			break
		}

		for j := 1; i+j < n; j++ {
			if s[i] == 0 && j > 1 {
				break
			}

			k := n - i - j
			if k < i || k < j {
				break
			}

			if check(0, i, i+j, n, s) {
				return true
			}
		}
	}
	return false
}

func check(st1, st2, en2, n int, s []int) bool {

	l1, l2 := st2-st1, en2-st2
	if en2+l1 > n || en2+l2 > n ||
		(l1 > 1 && s[st1] == 0) ||
		(l2 > 1 && s[st2] == 0) {
		return false
	}

	if (l1 > 1 || l2 > 1) && s[en2] == 0 {
		return false
	}

	i, j, carry := st2-1, en2-1, 0
	sum := []int{}
	for i >= st1 && j >= st2 {
		cur := s[i] + s[j] + carry
		carry = cur / 10
		cur %= 10

		sum = append([]int{cur}, sum...)
		i--
		j--
	}

	for i >= st1 {
		cur := s[i] + carry
		carry = cur / 10
		cur %= 10

		sum = append([]int{cur}, sum...)
		i--
	}

	for j >= st2 {
		cur := s[j] + carry
		carry = cur / 10
		cur %= 10

		sum = append([]int{cur}, sum...)
		j--
	}

	if carry != 0 {
		sum = append([]int{carry}, sum...)
	}

	if en2+len(sum) > n {
		return false
	}

	for k := 0; k < len(sum); k++ {
		if sum[k] != s[en2+k] {
			return false
		}
	}

	if en2+len(sum) == n {
		return true
	}
	return check(st2, en2, en2+len(sum), n, s)
}
