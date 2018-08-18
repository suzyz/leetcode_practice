package p704

func search(nums []int, target int) int {
	n := len(nums)
	if n == 0 || target > nums[n-1] || target < nums[0] {
		return -1
	}

	l, r := 0, n-1
	for l <= r {
		mid := l + ((r - l) >> 1)
		if nums[mid] == target {
			return mid
		} else if nums[mid] < target {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}

	return -1
}
