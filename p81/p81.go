func search(nums []int, target int) bool {
    if len(nums) == 0 {
    	return false
    }

    l := 0
    r := len(nums) - 1

    if nums[l] == target || nums[r] == target {
    	return true
    }

    for ; nums[l] == nums[r] && l < r; l++ {
    }
    for ; nums[0] == nums[r] && l < r; r-- {
    }

    for ; l <= r; {
    	mid := l + ((r - l) >> 1)

    	if nums[mid] == target{
    		return true
    	}

    	if nums[mid] <= nums[r] {
    		if nums[mid] < target && target <= nums[r] {
    			l = mid + 1
    		} else {
    			r = mid - 1
    		}
    	} else {
    		if nums[mid] > target && target >= nums[l] {
    			r = mid - 1
    		} else {
    			l = mid + 1
    		}
    	}
    }

    return false
}
