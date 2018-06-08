// Find the number of squares in [1,n]. Brutal.
package p319

import (
	"math"
)

func bulbSwitch(n int) int {
	res := 0
	for i := 1; i <= n; i++ {
		tmp := int(math.Sqrt(float64(i)))
		if tmp*tmp == i {
			res++
		}
	}
	return res
}
