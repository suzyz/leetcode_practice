package p456

func find132pattern(nums []int) bool {
	n := len(nums)
	if n < 3 {
		return false
	}

	top := 0
	st := []int{nums[0]}
	for i := 1; i < n; i++ {
		switch {
		case nums[i] > st[top]:
			top++
			st = append(st, nums[i])

		case nums[i] < st[top]:
			for top >= 0 && st[top] > nums[i] {
				st = st[:top]
				top--
				if top >= 0 && nums[i] > st[top] {
					return true
				}
			}
			top++
			st = append(st, nums[i])
		}
	}

	return false
}
