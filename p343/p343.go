func integerBreak(n int) int {
	if n == 2 {
		return 1
	}
	
    var f [60]int

    f[1], f[2] = 1, 1
    for i := 3; i <= n; i++ {
    	f[i] = 0
    	for k := 1; k < i; k++ {
    		if f[i-k]*k > f[i] {
    			f[i] = f[i-k]*k
    		}
    		if (i-k)*k > f[i] {
    			f[i] = (i-k)*k
    		}
    	}    
    }
    
    return f[n]
}
