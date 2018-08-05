// Sort and binary search. Not neat.
package p885

import (
	"sort"
)

func numRescueBoats(people []int, limit int) int {
	n := len(people)

	if n < 2 {
		return n
	}

	sort.Slice(people, func(i, j int) bool {
		return people[i] < people[j]
	})

	ans := 0
	for n >= 0 && people[n-1] >= limit {
		n--
		ans++
	}

	vis := make([]bool, n)

	j := n - 1
	for i := 0; i < n; i++ {
		if vis[i] {
			continue
		}

		ans++

		rem := limit - people[i]
		if i == n-1 || rem < people[i+1] {
			continue
		}

		for j >= i && people[j] > rem {
			j--
		}
		vis[j] = true
		j--
	}

	return ans
}
