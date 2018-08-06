package p219

func containsNearbyDuplicate(nums []int, k int) bool {
	m := make(map[int]bool)

	for i := 0; i < len(nums); i++ {
		if i > k {
			delete(m, nums[i-k-1])
		}

		if m[nums[i]] {
			return true
		}

		m[nums[i]] = true
	}

	return false
}
