package p541

func reverseStr(s string, k int) string {
	if k == 1 {
		return s
	}

	n := len(s)
	res := []byte(s)
	for i := 0; i < n; i += 2 * k {
		if i+k < n {
			reverse(i, i+k-1, res)
		} else {
			reverse(i, n-1, res)
		}
	}

	return string(res)
}

func reverse(l, r int, res []byte) {
	for l < r {
		res[l], res[r] = res[r], res[l]
		l++
		r--
	}
}
