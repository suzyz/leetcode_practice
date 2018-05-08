package p679

func judgePoint24(nums []int) bool {
	cur := make([]int, 4)
	used := make([]bool, 4)
	return getOrder(0, nums, cur, used)
}

func getOrder(i int, nums []int, cur []int, used []bool) bool {
	if i == 4 {
		if calc(cur) {
			return true
		} else {
			return false
		}
	}

	for j := 0; j < 4; j++ {
		if !used[j] {
			used[j] = true

			cur[i] = nums[j]
			if getOrder(i+1, nums, cur, used) {
				return true
			}

			used[j] = false
		}
	}
	return false
}

func calc(nums []int) bool {

	f := make([][][]float64, 4)
	for i := 0; i < 4; i++ {
		f[i] = make([][]float64, 4)
	}
	helper(0, 3, nums, &f)
	res := f[0][3]
	for _, i := range res {
		if math.Abs(i-24) < 1e-10 {
			return true
		}
	}
	return false
}

func helper(st, en int, nums []int, f *[][][]float64) {
	if en < st || len((*f)[st][en]) > 0 {
		return
	}

	if st == en {
		(*f)[st][en] = []float64{float64(nums[st])}
		return
	}

	(*f)[st][en] = []float64{}
	for i := st; i < en; i++ {
		helper(st, i, nums, f)
		helper(i+1, en, nums, f)

		for _, j := range (*f)[st][i] {
			a := float64(j)
			for _, t := range (*f)[i+1][en] {
				b := float64(t)
				insert(&(*f)[st][en], a+b)
				insert(&(*f)[st][en], a-b)
				insert(&(*f)[st][en], a*b)
				if math.Abs(b) > 1e-10 {
					insert(&(*f)[st][en], a/b)
				}
			}
		}
	}
}

func insert(res *[]float64, v float64) {
	for _, i := range *res {
		if math.Abs(i-v) < 1e-10 {
			return
		}
	}
	*res = append(*res, v)
}
