// Brutal. O(N).
package p350

func intersect(nums1 []int, nums2 []int) []int {
	m1, m2 := make(map[int]int), make(map[int]int)
	for _, v := range nums1 {
		m1[v]++
	}
	for _, v := range nums2 {
		m2[v]++
	}

	res := make([]int, 0)
	for k, v := range m1 {
		if m2[k] > 0 {
			if m2[k] < v {
				v = m2[k]
			}
			for i := 0; i < v; i++ {
				res = append(res, k)
			}
		}
	}
	return res
}
