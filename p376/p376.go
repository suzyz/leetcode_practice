// DP. O(n^2).
func wiggleMaxLength(nums []int) int {
    n := len(nums)
    if n < 2 {
    	return n
    }

    // f[i]: the max length of wiggle subsequence 
    // ending at i and the last difference is positive.

    // g[i]: similiar but the last difference is negative.

    ans := 1
    f := make([]int, n+1) 
    g := make([]int, n+1)
    f[0], g[0] = 1, 1
    for i := 1; i < n; i++ {
    	f[i], g[i] = 1, 1
    	for j := 0; j < i; j++ {
    		if nums[i] > nums[j] {
    			f[i] = max(f[i], g[j] + 1)
    		} else if nums[i] < nums[j] {
    			g[i] = max(g[i], f[j] + 1)
    		}
    	}

    	ans = max(ans, max(f[i], g[i]))
    }

    return ans
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
