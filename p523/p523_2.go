// With map or set. O(N) time.
// Note that k can be zero.

package p523

func checkSubarraySum(nums []int, k int) bool {
	sum, pre := 0, 0
	setOfSums := make(map[int]bool)

	for _, v := range nums {
		sum += v
		if k != 0 {
			sum %= k
		}

		if setOfSums[sum] {
			return true
		}

		setOfSums[pre] = true
		pre = sum
	}

	return false
}
