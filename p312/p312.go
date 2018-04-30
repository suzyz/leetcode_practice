package p312

const maxn = 510

func maxCoins(nums []int) int {
	n := len(nums)

	nums = append([]int{1}, nums...)
	nums = append(nums, 1)

	n += 2
	f := make([][]int, n)
	for i := 0; i < n; i++ {
		f[i] = make([]int, n)
	}

	for l := 3; l <= n; l++ {
		for en := l - 1; en < n; en++ {
			st := en - l + 1

			for k := st + 1; k < en; k++ {
				cur := f[st][k] + f[k][en] + nums[st]*nums[k]*nums[en]
				if cur > f[st][en] {
					f[st][en] = cur
				}
			}
		}
	}

	return f[0][n-1]
}
