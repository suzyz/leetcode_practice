// O(n) time, O(n) space.

func findUnsortedSubarray(nums []int) int {
    n := len(nums)
    if n < 2 {
    	return 0
    }
    
    maxv := make([]int, n+1)
    maxv[0] = nums[0]
    for i := 1; i < n; i++ {
        maxv[i] = max(maxv[i-1], nums[i])
    }

    minv := make([]int, n+1)
    minv[n-1], minv[n] = nums[n-1], 1e10
    for i := n-2; i >= 0; i-- {
        minv[i] = min(minv[i+1], nums[i])
    }

    l := 0
    for i := 0; i < n && nums[i] <= minv[i+1]; i++ {
        l++
    }

    if l == n {
        return 0
    }

    r := n-1
    for i := n-1; i > 0 && nums[i] >= maxv[i-1]; i-- {
        r--
    }

    return r-l+1
}

func min(a, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}