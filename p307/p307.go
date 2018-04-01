// Binary indexed tree. 树状数组。
package p307

type NumArray struct {
	nums []int
	sum  []int
}

func Constructor(nums []int) NumArray {
	n := len(nums)
	res := NumArray{}
	res.nums = make([]int, n+1)
	res.sum = make([]int, n+1)

	for i := 1; i <= n; i++ {
		res.nums[i] = nums[i-1]
		res.sum[i] = nums[i-1]
		for j := i - 2; j >= i-lowbit(i); j-- {
			res.sum[i] += nums[j]
		}
	}

	return res
}

func (this *NumArray) Update(i int, val int) {
	i++
	delta := val - this.nums[i]
	this.nums[i] = val
	for j := i; j < len(this.nums); j += lowbit(j) {
		this.sum[j] += delta
	}
}

func (this *NumArray) SumRange(i int, j int) int {
	return this.accSum(j+1) - this.accSum(i)
}

func (this *NumArray) accSum(k int) int {
	ans := 0
	for i := k; i > 0; i -= lowbit(i) {
		ans += this.sum[i]
	}
	return ans
}

func lowbit(i int) int {
	return i & (-i)
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * obj.Update(i,val);
 * param_2 := obj.SumRange(i,j);
 */
