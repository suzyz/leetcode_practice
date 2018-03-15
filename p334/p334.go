func increasingTriplet(nums []int) bool {
    n := len(nums)
    if n < 3 {
    	return false
    }

    min1, min2 := nums[0], int(1 << 50)

    for i := 1; i < n; i++ {
    	if nums[i] > min2 {
    		return true
    	} else if nums[i] < min1 {
    		min1 = nums[i]
    	} else if nums[i] > min1 && nums[i] < min2 {
    		min2 = nums[i]
    	}
    }

    return false
}
