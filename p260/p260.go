//to be continued.
package p260

func singleNumber(nums []int) []int {
	n := len(nums)
	tmp := 0
	for _, v := range nums {
		tmp ^= v
	}
}
