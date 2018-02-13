func findLHS(nums []int) int {

    m := make(map[int]int)
    for _, v := range nums {
    	m[v]++
    }

    ans := 0
    for i,v := range m {
    	if w, ok := m[i+1]; ok {
    		if w + v > ans {
    			ans = w + v
    		}
    	}
    }

    return ans
}
