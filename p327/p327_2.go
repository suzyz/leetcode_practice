// Still O(nlogn) but much faster. Using sort.Search.
func countRangeSum(nums []int, lower int, upper int) int {
	n := len(nums)
	if n == 0 {
		return 0
	}
	sum := make([]int, n+1)
	for i := 0; i < n; i++ {
		sum[i+1] = sum[i] + nums[i]
	}
	sorted := make([]int, n)
	copy(sorted, sum[1:])
	sort.Slice(sorted, func(i, j int) bool {
		return sorted[i] < sorted[j]
	})

	res := 0
	// To find all valid (i, j) pairs s.t. sum[j] - sum[i] is in the given range,
	// numerate i
	for i := 0; i < n; i++ {
		l := sort.Search(len(sorted), func(idx int) bool {
			return sorted[idx] >= lower+sum[i]
		})
		if l != len(sorted) {
			r := sort.Search(len(sorted), func(idx int) bool {
				return sorted[idx] > upper+sum[i]
			})
			res += r - l
		}

		l = sort.Search(len(sorted), func(idx int) bool {
			return sorted[idx] >= sum[i+1]
		})
		sorted = append(sorted[:l], sorted[l+1:]...)
	}
	return res
}
