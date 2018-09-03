package p4

import (
	"sort"
)

func orderlyQueue(S string, K int) string {

	if K == 1 {
		res := S
		for i := 1; i < len(S); i++ {
			tmp := S[i:] + S[:i]
			if tmp < res {
				res = tmp
			}
		}

		return res
	}

	// when K > 1, use counting sort
	count := make([]int, 26)
	for _, c := range S {
		count[c-'a']++
	}

	bytes := make([]byte, 0)
	for i := 0; i < 26; i++ {
		for count[i] > 0 {
			bytes = append(bytes, byte(i+'a'))
			count[i]--
		}
	}

	return string(bytes)
}
