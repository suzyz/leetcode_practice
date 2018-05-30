package p763

func partitionLabels(S string) []int {
	var maxPos [200]int
	for j, c := range S {
		maxPos[c] = j
	}

	res, st, en := []int{}, 0, 0

	for i, c := range S {
		if maxPos[c] > en {
			en = maxPos[c]
		}

		if i == en {
			res = append(res, en-st+1)
			st = i + 1
		}
	}

	return res
}
