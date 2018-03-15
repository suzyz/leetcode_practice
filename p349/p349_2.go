// Easier.
func intersection(nums1 []int, nums2 []int) []int {
    s := make(map[int]bool)
   	for _, v := range nums1 {
   		s[v] = true
   	}

    res := make([]int, 0)
   	for _, v := range nums2 {
   		if s[v] == true {
   			res = append(res, v)
            delete(s, v)
   		}
   	}

   	return res
}
