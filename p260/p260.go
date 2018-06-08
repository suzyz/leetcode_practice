// Calculate the xor of all numbers,
// devide the numbers into two categories by one digit(not zero) of the XOR,
// and we can find one answer in each group.
package p260

func singleNumber(nums []int) []int {
	xor := 0
	for _, v := range nums {
		xor ^= v
	}

	digit := xor & (-xor)
	n1 := 0
	for _, v := range nums {
		if v&digit == 0 {
			n1 ^= v
		}
	}

	res := []int{n1, n1 ^ xor}
	return res
}
