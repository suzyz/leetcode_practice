
func canPartitionKSubsets(nums []int, k int) bool {
	n := len(nums)
	if n < k {
		return false
	}

	sum := 0
	for i := 0; i < n; i++ {
		sum += nums[i]
	}
	if sum%k != 0 {
		return false
	}

	used := make([]bool, n)
	return dfs(0, n, 0, sum/k, k, nums, used)
}

func dfs(start, n, curSum, target, leftSubsets int, nums []int, used []bool) bool {
	if leftSubsets == 0 {
		return true
	}

	for i := start; i < n; i++ {
		if !used[i] && nums[i]+curSum <= target {
			used[i] = true
			if nums[i]+curSum == target {
				if dfs(0, n, 0, target, leftSubsets-1, nums, used) {
					return true
				}
			} else {
				if dfs(i+1, n, curSum+nums[i], target, leftSubsets, nums, used) {
					return true
				}
			}
			used[i] = false
		}
	}
    return false
}
