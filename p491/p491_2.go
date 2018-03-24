// Iteration. Rather than recursion. Still TLE.

func findSubsequences(nums []int) [][]int {

    n := len(nums)
    m := make(map[int]int)
    cur := make([][]int, 1)
    cur[0] = []int{}

    var ans [][]int
    for i := 0; i < n; i++ {
    	lim := len(cur)

    	st, ok := m[nums[i]]
    	if !ok {
    		st = 0
    	}

    	m[nums[i]] = lim

    	for j := st; j < lim; j++ {
    		if len(cur[j]) > 0 && nums[i] < cur[j][len(cur[j])-1] {
    			continue
    		}

    		tmp := append(cur[j], nums[i])
    		cur = append(cur, tmp)

    		if len(tmp) >= 2 {
    			ans = append(ans, tmp)
    		}
    	}
    }

    return ans
}
