func findSubsequences(nums []int) [][]int {
	var cur []int
    var ans [][]int
    dfs(0, -200, cur, nums, &ans)
    return ans
}

func dfs(start, last int, cur []int, nums []int, ans *[][]int) {
	if len(cur) > 1 {
			tmp := make([]int, len(cur))
			copy(tmp, cur)
			*ans = append(*ans, tmp)
	}

	var used []int

	for i := start; i < len(nums); i++ {
		if nums[i] < last {
			continue
		}

		flag := true
		for _, v := range used {
			if v == nums[i] {
				flag = false
				break
			}
		}
		if !flag {
			continue
		}
        
		used = append(used, nums[i])

		cur = append(cur, nums[i])
		dfs(i+1, nums[i], cur, nums, ans)
		cur = cur[:len(cur)-1]	
	}
}