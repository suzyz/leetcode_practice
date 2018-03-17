func lengthOfLIS(nums []int) int {
    n := len(nums)
    if n < 2 {
    	return n
    }

    f := make([]int, n+1)
    f[1] = nums[0]

    ans := 1
    for i := 1; i < n; i++ {
    	if nums[i] > f[ans] {
    		ans++
    		f[ans] = nums[i]
    	} else if nums[i] < f[ans] {
    		pos := binarySearch(f, ans, nums[i])
    		f[pos] = nums[i]	
    	}
    }

    return ans
}

// return pos, s.t. nums[pos-1] < d <= nums[pos]
func binarySearch(nums []int, tot, d int) int {
	l, r := 1, tot
	for l < r {
		mid := l + ((r-l)>>1)
		if d == nums[mid] {
			return mid
		} else if d < nums[mid] {
			r = mid
		} else {
			l = mid + 1
		}
	}

	return l
}
