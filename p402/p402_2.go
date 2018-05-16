// O(n). Stack.
package p402

func removeKdigits(num string, k int) string {
	n := len(num)
	if n == k {
		return "0"
	}

	top := 0
	st := make([]byte, n)

	for i := 0; i < n; i++ {
		for top > 0 && num[i] < st[top-1] && k > 0 {
			top--
			k--
		}

		st[top] = num[i]
		top++
	}

	for top > 0 && k > 0 {
		top--
		k--
	}

	i := 0
	for i < top-1 && st[i] == '0' {
		i++
	}

	return string(st[i:top])
}
