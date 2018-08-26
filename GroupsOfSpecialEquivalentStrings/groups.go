package GroupsOfSpecialEquivalentStrings

func numSpecialEquivGroups(A []string) int {
	n, res := len(A), 0
	// subsets := make([]string, 0)
	used := make(map[int]bool)
	for i := 0; i < n; i++ {
		if !used[i] {
			res++

			for j := i + 1; j < n; j++ {
				if !used[j] && isEqual(A[i], A[j]) {
					used[j] = true
				}
			}
		}
	}

	return res
}

func isEqual(a, b string) bool {
	count1 := make(map[byte]int)
	n := len(a)
	for i := 0; i < n; i += 2 {
		count1[a[i]]++
		count1[b[i]]--
	}

	for _, v := range count1 {
		if v != 0 {
			return false
		}
	}

	for i := 1; i < n; i += 2 {
		count1[a[i]]++
		count1[b[i]]--
	}

	for _, v := range count1 {
		if v != 0 {
			return false
		}
	}

	return true
}
