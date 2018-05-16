// O((n-k)*k). Plain.
package p402

func removeKdigits(num string, k int) string {
	n := len(num)
	if n == k {
		return "0"
	}

	last := -1
	res := []byte{}
	for i := 0; i < n-k; i++ {
		best := int(num[last+1]) - '0'
		bestIdx := last + 1
		for j := last + 2; j <= k+i; j++ {
			v := int(num[j]) - '0'

			if v < best {
				bestIdx = j
				best = v
			}
		}

		res = append(res, num[bestIdx])
		last = bestIdx
	}

	for len(res) > 1 && res[0] == '0' {
		res = res[1:]
	}

	return string(res)
}
