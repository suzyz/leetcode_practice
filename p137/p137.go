func singleNumber(nums []int) int {
    ones, twos := 0, 0
    for _, v := range nums {
    	ones = (ones ^ v) & (^twos)
    	twos = (twos ^ v) & (^ones)
    }
    return ones
}
