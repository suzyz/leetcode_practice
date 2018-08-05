// Sort and two pointers. Neat.
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
	l, r := 0, n-1

	for l <= r {
		if people[l]+people[r] <= limit {
			l++
		}

		r--
		ans++
	}
	return ans
}
