package p747

func dominantIndex(nums []int) int {
	n := len(nums)
	maxv, secondMaxv, best := -1, -1, -1
	for i := 0; i < n; i++ {
		if nums[i] > maxv {
			best = i
			secondMaxv = maxv
			maxv = nums[i]
		} else if nums[i] > secondMaxv {
			secondMaxv = nums[i]
		}
	}

	if maxv >= 2*secondMaxv {
		return best
	} else {
		return -1
	}
}
