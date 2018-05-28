package p330

func minPatches(nums []int, n int) int {
	m := make(map[int]bool)

	m[0] = true
	for _, v := range nums {
		for j := n; j >= v; j-- {
			if m[j-v] {
				m[j] = true
			}
		}
	}

	res := 0
	for len(m) < n+1 {
		res++
		k := 0
		for k = 1; k <= n; k++ {
			if !m[k] {
				break
			}
		}

		for j := n; j >= k; j-- {
			if m[j-k] {
				m[j] = true
			}
		}
	}
	return res
}
