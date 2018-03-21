func findUnsortedSubarray(nums []int) int {
    n := len(nums)
    if n < 2 {
    	return 0
    }

    idx := -1
    for i := 1; i < n; i++ {
    	if nums[i] < nums[i-1] {
    		idx1 = i
    		break
    	}
    }

    if idx == -1 {
    	return 0
    }

    ans := n - idx
    for 
}
