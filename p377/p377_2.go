// Top-down.
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

	nums = nums[:n]

	f := make([]int, target+1)
	f[0] = 1
	for i := 1; i <= target; i++ {
		f[i] = -1
	}

	return helper(nums, f, target)
}

func helper(nums, f []int, target int) int {
	if f[target] >= 0 {
		return f[target]
	}

	f[target] = 0
	for _, v := range nums {
		if v <= target {
			f[target] += helper(nums, f, target-v)
		}
	}
	return f[target]
}
