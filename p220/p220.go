
func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
	if k == 1 {
		return (t == 0)
	}
    if len(nums) < 2 {
    	return false
    }

    n := len(nums)

   	for i := 0; i < n; i++ {
   		for j := i + 1; j <= i + k && j < n; j++ {
   			k := nums[j] - nums[i]
   			if k < 0 {
   				k = -k
   			}

   			if k <= t {
   				return true
   			}
   		} 
   	}

   	return false
}
