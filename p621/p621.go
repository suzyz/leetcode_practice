package p621

const tot = 26

func leastInterval(tasks []byte, n int) int {

	maxCount := 0

	count := make([]int, tot)
	for _, c := range tasks {
		count[c-'A']++
	}

	for _, v := range count {
		if v > maxCount {
			maxCount = v
		}
	}

	res := (maxCount - 1) * (n + 1)
	for _, v := range count {
		if v == maxCount {
			res++
		}
	}

	if res < len(tasks) {
		res = len(tasks)
	}

	return res
}
