// Sort + Plain DP. O(N^2)
func findLongestChain(pairs [][]int) int {
    n := len(pairs)
    if n < 2 {
    	return n
    }

    sort.Slice(pairs, func(i, j int) bool {
    		return pairs[i][1] < pairs[j][0] ||
    			pairs[i][0] < pairs[j][0]
    	})

    f := make([]int, n)
    f[0] = 1
    for i := 1; i < n; i++ {
    	f[i] = 1
    	for j := i-1; j >= 0; j-- {
    		if pairs[i][0] > pairs[j][1] && f[i] < f[j]+1 {
    			f[i] = f[j]+1
    		}
    	}
    }

    ans := 1
    for _, v := range f {
    	if v > ans {
    		ans = v
    	}
    }
    return ans
}
