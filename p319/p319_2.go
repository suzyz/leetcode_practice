// Find the number of squares in [1,n]. O(sqrt(n))
package p319

import (
	"math"
)

func bulbSwitch(n int) int {
	res := 1
	for res*res <= n {
		res++
	}
	res--
	return res
}
