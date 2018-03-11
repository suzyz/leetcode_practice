func integerBreak(n int) int {
	if n == 2 {
		return 1
	}
    if n == 3 {
        return 2
    }
	
    res := 1
    for n > 4 {
        n -= 3
        res *= 3
    }

    res *= n
    
    return res
}
