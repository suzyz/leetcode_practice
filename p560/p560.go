package p560

func subarraySum(nums []int, k int) int {

	sum, res := 0, 0
	count := make(map[int]int)
	count[0] = 1

	for i := range nums {
		sum += nums[i]
		res += count[sum-k]

		count[sum]++
	}
	return res
}
