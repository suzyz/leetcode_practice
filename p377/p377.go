// Bottom-up.
// Note that the order in the sequence matters,
// which means that [1,1,2] and [1,2,1] are different answers.
package p377

import "sort"

func combinationSum4(nums []int, target int) int {
	n := len(nums)
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	for n > 0 && nums[n-1] > target {
		n--
	}

	f := make([]int, target+1)
	f[0] = 1
	for j := 1; j <= target; j++ {
		for i := 0; i < n; i++ {
			if j >= nums[i] {
				f[j] += f[j-nums[i]]
			}
		}
	}
	return f[target]
}
