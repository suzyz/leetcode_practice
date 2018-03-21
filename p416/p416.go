func canPartition(nums []int) bool {
    sum := 0
    for _, v := range nums {
    	sum += v
    }

    if sum % 2 != 0 {
    	return false
    }
   
   	target, n := sum/2, len(nums) 
    f := make([]bool, target+1)
    f[0] = true

    for i := 0; i < n; i++ {
    	if nums[i] > target {
    		continue
    	}

    	if f[target - nums[i]] {
    		return true
    	}

    	for j := target-1; j >= nums[i]; j-- {
    		if f[j - nums[i]] {
    			f[j] = true
    		}
    	}
    }

    return f[target]
}
