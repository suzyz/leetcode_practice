// Brutal.
// Note that k can be zero.

package p523

func checkSubarraySum(nums []int, k int) bool {
	n := len(nums)

	for i := 0; i < n-1; i++ {
		sum := nums[i]

		for j := i + 1; j < n; j++ {
			sum += nums[j]

			if (k == 0 && sum == 0) || (k != 0 && sum%k == 0) {
				return true
			}
		}
	}
	return false
}
