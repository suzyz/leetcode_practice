func findDuplicate(nums []int) int {
    m := make(map[int]bool)
   	for _, v := range nums {
   		if m[v] == true {
   			return v
   		}
   		m[v] = true
   	}

    return 0
}
