package p739

func dailyTemperatures(temperatures []int) []int {
	n := len(temperatures)
	m := make(map[int]int, 71) // 100 - 30 + 1 = 71
	m[temperatures[n-1]] = n - 1

	ans := make([]int, n)
	ans[n-1] = 0

	maxt := temperatures[n-1]

	for i := n - 2; i >= 0; i-- {
		if maxt <= temperatures[i] {
			ans[i] = 0
			m[temperatures[i]] = i
			maxt = temperatures[i]
		} else {
			earlistDay := n - 1
			for j := temperatures[i] + 1; j <= maxt; j++ {
				if day, ok := m[j]; ok && day < earlistDay {
					earlistDay = day
				}
			}

			ans[i] = earlistDay - i
			m[temperatures[i]] = i
		}
	}

	return ans
}
