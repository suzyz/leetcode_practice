package p476

func findComplement(num int) int {
	if num == 0 {
		return 1 // wtf.
	}
	var mask int
	mask = ^0

	for mask&num != 0 {
		mask <<= 1
	}

	return (^mask) & (^num)
}
