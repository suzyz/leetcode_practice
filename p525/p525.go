package p525

func findMaxLength(nums []int) int {
	n, sum, maxl := len(nums), 0, 0
	m := make(map[int]int)
	m[0] = -1

	for i := 0; i < n; i++ {
		if nums[i] == 1 {
			sum++
		} else {
			sum--
		}

		if pos, ok := m[sum]; ok {
			if maxl < i-pos {
				maxl = i - pos
			}
		} else {
			m[sum] = i
		}
	}

	return maxl
}
