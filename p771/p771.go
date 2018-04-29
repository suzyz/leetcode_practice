package p771

func numJewelsInStones(J string, S string) int {
	isJewel := make(map[rune]bool)

	for _, b := range J {
		isJewel[b] = true
	}

	res := 0
	for _, b := range S {
		if isJewel[b] {
			res++
		}
	}
	return res
}
