package p228

import (
	"strconv"
)

func summaryRanges(nums []int) []string {
	n := len(nums)

	ans := make([]string, 0)
	i := 0
	for i < n {
		j := i + 1
		for j < n && nums[j] == nums[j-1]+1 {
			j++
		}

		j--
		if i == j {
			ans = append(ans, strconv.Itoa(nums[i]))
		} else {
			ans = append(ans, strconv.Itoa(nums[i])+"->"+strconv.Itoa(nums[j]))
		}
		i = j + 1
	}

	return ans
}
