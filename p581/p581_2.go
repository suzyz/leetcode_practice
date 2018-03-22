// O(n) time, O(1) space.

func findUnsortedSubarray(nums []int) int {
    n := len(nums)
    if n < 2 {
    	return 0
    }

    isPeak := false
    var minv int = 1e10
    for i := 0; i < n; i++ {
        if isPeak {
            minv = min(minv, nums[i])
        } else if i < n-1 && nums[i] > nums[i+1] {
            isPeak = true
        }
    }

    if !isPeak {
        return 0
    }

    isValley := false
    var maxv int = -(1e10)
    for i := n-1; i >= 0; i-- {
        if isValley {
            maxv = max(maxv, nums[i])
        } else if i > 0 && nums[i] < nums[i-1] {
            isValley = true
        }
    }

    var l, r int
    for i := 0; i < n; i++ {
        if nums[i] > minv {
            l = i
            break
        }
    }

    for i := n-1; i >= 0; i-- {
        if nums[i] < maxv {
            r = i
            break
        }
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