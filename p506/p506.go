package p506

import (
	"sort"
	"strconv"
)

var medals = [3]string{"Gold Medal", "Silver Medal", "Bronze Medal"}

func findRelativeRanks(nums []int) []string {
	n := len(nums)

	if n == 0 {
		return []string{}
	}

	idx := make([]int, n)
	for i := 0; i < n; i++ {
		idx[i] = i
	}

	sort.Slice(idx, func(i, j int) bool {
		return nums[idx[i]] > nums[idx[j]]
	})

	res := make([]string, n)
	for i := 0; i < 3 && i < n; i++ {
		res[idx[i]] = medals[i]
	}
	for i := 3; i < n; i++ {
		res[idx[i]] = strconv.Itoa(i + 1)
	}

	return res
}
