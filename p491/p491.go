// DFS. TLE at case [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]

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

	used := make([]bool, 201)

	for i := start; i < len(nums); i++ {
		if nums[i] < last {
			continue
		}

		if used[nums[i]+100] {
			continue
		}
        
		used[nums[i]+100] = true

		cur = append(cur, nums[i])
		dfs(i+1, nums[i], cur, nums, ans)
		cur = cur[:len(cur)-1]	
	}
}