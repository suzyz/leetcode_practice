// Too slow.
package p327

func countRangeSum(nums []int, lower int, upper int) int {
	n := len(nums)
	if n == 0 {
		return 0
	}
	previousSums := make([]int, 1)
	previousSums[0] = 0
	curSum, res := 0, 0

	for i := 0; i < n; i++ {
		curSum += nums[i]
		// locate
		min, max := 0, 0
		l, r := 0, i
		target := curSum - lower
		if target < previousSums[0] {
			insert(&previousSums, curSum)
			continue
		}
		for l < r {
			mid := ((r + l) >> 1) + 1
			if previousSums[mid] <= target {
				l = mid
			} else {
				r = mid - 1
			}
		}
		max = l

		l, r = 0, i
		target = curSum - upper
		if target > previousSums[i] {
			insert(&previousSums, curSum)
			continue
		}
		for l < r {
			mid := (r + l) >> 1
			if previousSums[mid] >= target {
				r = mid
			} else {
				l = mid + 1
			}
		}
		min = l
		res += max - min + 1

		insert(&previousSums, curSum)
	}
	return res
}

func insert(previousSums *[]int, curSum int) {
	if curSum <= (*previousSums)[0] {
		*previousSums = append([]int{curSum}, *previousSums...)
	} else {
		n := len((*previousSums))
		if curSum >= (*previousSums)[n-1] {
			*previousSums = append(*previousSums, curSum)
		} else {
			l, r := 0, n-1
			for l < r {
				mid := (r + l) >> 1
				if (*previousSums)[mid] == curSum {
					l, r = mid, mid
					break
				} else if (*previousSums)[mid] > curSum {
					r = mid
				} else {
					l = mid + 1
				}
			}

			tail := append([]int{}, (*previousSums)[l:]...)
			*previousSums = append((*previousSums)[:l], curSum)
			*previousSums = append(*previousSums, tail...)
		}
	}
}
