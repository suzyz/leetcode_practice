// O(N). With optimization.
// 1. Only use one map to memorize the numbers in the shorter array.
// 2. When the map is empty, stop the process.

package p350

func intersect(nums1 []int, nums2 []int) []int {
	var shorter, longer *[]int
	if len(nums1) < len(nums2) {
		shorter = &nums1
		longer = &nums2
	} else {
		shorter = &nums2
		longer = &nums1
	}

	m := make(map[int]int)
	for _, v := range *shorter {
		m[v]++
	}

	res := make([]int, 0)
	for _, v := range *longer {
		if m[v] > 0 {
			res = append(res, v)
			m[v]--
			if m[v] == 0 {
				delete(m, v)
				if len(m) == 0 {
					break
				}
			}
		}
	}
	return res
}
