// O(N)
package p740

const (
	maxLength = 10002
)

func deleteAndEarn(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	buckets := make([]int, maxLength)
	for _, v := range nums {
		buckets[v]++
	}

	last := -1
	skip, newSkip, pick, newPick := 0, 0, 0, 0

	for i := 1; i < maxLength; i++ {
		if buckets[i] == 0 {
			continue
		}

		newSkip = max(pick, skip)

		if last == i-1 {
			newPick = skip + i*buckets[i]
		} else {
			newPick = newSkip + i*buckets[i]
		}

		skip, pick = newSkip, newPick
		last = i
	}

	return max(skip, pick)
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
