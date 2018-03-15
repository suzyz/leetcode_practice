// Plain.
func intersection(nums1 []int, nums2 []int) []int {
    s1 := make(map[int]bool)
    s2 := make(map[int]bool)
   	for _, v := range nums1 {
   		s1[v] = true
   	}

   	for _, v := range nums2 {
   		if s1[v] == true {
   			s2[v] = true
   		}
   	}

   	res := make([]int, 0)
   	for k := range s2 {
   		res = append(res, k)
   	}

   	return res
}
