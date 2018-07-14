package p565

func arrayNesting(nums []int) int {
	n := len(nums)
	if n < 2 {
		return n
	}

	ans := 0
	vis := make([]bool, n)
	for i := 0; i < n; i++ {
		j, count := nums[i], 1
		vis[i] = true
		for !vis[j] {
			count++
			j = nums[j]
		}
		if count > ans {
			ans = count
		}
	}

	return ans
}
