package p670

func maximumSwap(num int) int {
	if num < 10 {
		return num
	}

	digits := []int{}

	i := num
	for i > 0 {
		digits = append(digits, i%10)
		i /= 10
	}

	helper(digits, len(digits)-1)

	res, w := 0, 1
	for _, d := range digits {
		res += d * w
		w *= 10
	}

	return res
}

func helper(digits []int, lim int) {

	if lim == 0 {
		return
	}

	bestIdx := lim
	for i := 0; i < lim; i++ {
		if digits[i] > digits[bestIdx] {
			bestIdx = i
		}
	}

	if bestIdx == lim {
		helper(digits, lim-1)
	} else {
		fmt.Println(bestIdx, digits)
		digits[bestIdx], digits[lim] = digits[lim], digits[bestIdx]
		fmt.Println(bestIdx, digits)
	}
}
