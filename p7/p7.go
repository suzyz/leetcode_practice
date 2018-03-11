func reverse(x int) int {
    isNegative := false
    if x < 0 {
    	isNegative = true
    	x = -x
    }

   	res := 0
   	for x > 0 {
   		d := x % 10
   		res = 10 * res + d
   		x /= 10
   	}

   	if isNegative {
   		res = -res
   	}

   	if res > 2147483647 || res < -2147483648 {
   		return 0
   	} else {
		return res
   	}
}
