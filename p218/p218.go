package p218

func getSkyline(buildings [][]int) [][]int {
	n := len(buildings)
	res := make([][]int, 0)
	if n == 0 {
		return res
	}

	res = append(res, []int{buildings[0][0], buildings[0][2]})
	curHeight := buildings[0][2]
	curMaxX := buildings[0][1]

	for i := 1; i < n; i++ {
		l, r, h := buildings[i][0], buildings[i][1], buildings[i][2]

		if l > curMaxX {
			res = append(res, []int{curMaxX, 0})
			res = append(res, []int{l, h})
			curHeight = h
			curMaxX = r
		} else {
			if 



			
		}

	}

}
