// O(N*logN)
package p740

import (
	"sort"
)

type num struct {
	val, count int
}

func deleteAndEarn(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})

	data, tot := []num{}, 0

	for _, v := range nums {
		if tot == 0 || v != data[tot-1].val {
			tot++
			data = append(data, num{
				val:   v,
				count: 1,
			})
		} else {
			data[tot-1].count++
		}
	}

	x := data[0].count * data[0].val

	if tot == 1 {
		return x
	}

	y, z := 0, 0
	if data[1].val-data[0].val != 1 {
		y = x + data[1].count*data[1].val
	} else {
		if data[1].count*data[1].val > x {
			y = data[1].count * data[1].val
		} else {
			y = x
		}
	}

	if tot == 2 {
		return y
	}

	for i := 2; i < tot; i++ {
		cur := data[i].count * data[i].val

		if data[i].val-data[i-1].val == 1 {
			if cur+x > y {
				z = cur + x
			} else {
				z = y
			}
		} else {
			if x > y {
				z = x + cur
			} else {
				z = y + cur
			}
		}

		x, y, z = y, z, 0
	}

	return y
}
