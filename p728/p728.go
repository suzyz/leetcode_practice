package p728

func selfDividingNumbers(left int, right int) []int {
	res := []int{}
	for i := left; i <= right; i++ {
		if check(i) {
			res = append(res, i)
		}
	}
	return res
}

func check(cur int) bool {
	tmp := cur
	for tmp > 0 {
		lastdigit := tmp % 10
		if lastdigit == 0 || cur%lastdigit != 0 {
			return false
		}

		tmp /= 10
	}

	return true
}
