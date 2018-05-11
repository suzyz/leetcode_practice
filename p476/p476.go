package p476

func findComplement(num int) int {
	if num == 0 {
		return 1
	}
	var n uint
	n = 31
	for n > 0 {
		if num&(1<<n) != 0 {
			break
		} else {
			n--
		}
	}

	tot := (1 << (n + 1)) - 1
	return tot ^ num
}
