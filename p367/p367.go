package p367

func isPerfectSquare(num int) bool {
	if num == 1 {
		return true
	}
	if num < 4 {
		return false
	}

	l, r := 2, num/2
	for l < r {
		mid := (l + r) >> 1
		v := mid * mid
		if v == num {
			return true
		} else if v < num {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	if l*l == num {
		return true
	} else {
		return false
	}
}
