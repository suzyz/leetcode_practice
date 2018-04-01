
func largestDivisibleSubset(nums []int) []int {
	n := len(nums)
	if n < 2 {
		return nums
	}
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})

	f, p := make([]int, n), make([]int, n)
	for i := 0; i < n-1; i++ {
		if f[i] == 0 {
			f[i] = 1
            p[i] = -1
		}
		for j := i + 1; j < n; j++ {
			if nums[j]%nums[i] == 0 && f[j] < f[i]+1 {
				f[j] = f[i] + 1
				p[j] = i
			}
		}
	}

	best := 0
	for i := 1; i < n; i++ {
		if f[i] > f[best] {
			best = i
		}
	}

	res := make([]int, 0)
	for best >= 0 {
		res = append(res, nums[best])
		best = p[best]
	}
	return res
}
