func findDisappearedNumbers(nums []int) []int {
    for _, v := range nums {
    	if v < 0 {
    		v = -v
    	}

    	if nums[v-1] > 0 {
    		nums[v-1] = -nums[v-1]
        }
    }

    var ans []int
    for i := range nums {
    	if nums[i] > 0 {
    		ans = append(ans, i+1)
    	}
    }

    return ans
}
