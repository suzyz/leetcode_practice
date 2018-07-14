// let m1 = len(s1),
// then the time complexity is O(m1*n1)

package p466

func getMaxRepetitions(s1 string, n1 int, s2 string, n2 int) int {

	m1, m2 := len(s1), len(s2)
	if n1 == 0 || m1 == 0 {
		return 0
	}
	if m2 == 0 {
		return -1
	}

	i, j, count1, count2 := 0, 0, 0, 0

	for k := 0; k < m1; k++ {
		if s1[k] == s2[j] {
			j++
			if j == m2 {
				j = 0
				count2++
			}
		}
	}

	if j == 0 {
		return count2 * n1 / n2
	}

	j, count2 = 0, 0
	for count1 < n1 {
		if s1[i] == s2[j] {
			j++
			if j == m2 {
				j = 0
				count2++
			}
		}

		i++
		if i == m1 {
			i = 0
			count1++
		}
	}

	return count2 / n2
}
