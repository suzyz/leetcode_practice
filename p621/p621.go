package p621

const maxtime = (1 << 31) - 1

func leastInterval(tasks []byte, n int) int {
	m := len(tasks)

	count := make([]int, 26)
	for _, c := range tasks {
		count[c-'A']++
	}
	next := make([]int, 26)
	for i := 0; i < 26; i++ {
		if count[i] == 0 {
			next[i] = maxtime
		}
	}

	curTime := 0
	for m > 0 {
		m--

		k := 0
		for i := 1; i < 26; i++ {
			if next[i] < next[k] || (next[i] == next[k] && count[i] > count[k]) {
				k = i
			}
		}

		if next[k] == maxtime {
			return -1
		}

		count[k]--
		if next[k] > curTime {
			curTime = next[k] + 1

			if count[k] > 0 {
				next[k] = curTime + n - 1
			} else {
				next[k] = maxtime
			}
		} else {
			curTime++

			if count[k] > 0 {
				next[k] = curTime + n
			} else {
				next[k] = maxtime
			}
		}

		fmt.Println(k)
		fmt.Println(next)
	}
	return curTime
}
