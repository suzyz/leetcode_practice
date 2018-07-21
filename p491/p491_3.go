package main

import (
	"fmt"
	"time"
)

func main() {
	d := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
	t1 := time.Now()
	_ = findSubsequences(d)
	t2 := time.Now()
	fmt.Println(t2.Sub(t1))

	d = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
	t1 = time.Now()
	_ = findSubsequences(d)
	fmt.Println(time.Since(t1))
}

func findSubsequences(nums []int) [][]int {
	n := len(nums)
	m := make(map[int]int)

	tot := (1 << uint(n)) + 1
	cur := make([][]int, tot)
	var ans [][]int

	cur[0] = []int{}
	curSize := 1
	//ansSize := 0

	for i := 0; i < n; i++ {
		lim := curSize

		st, ok := m[nums[i]]
		if !ok {
			st = 0
		}

		m[nums[i]] = lim

		for j := st; j < lim; j++ {
			if len(cur[j]) > 0 && nums[i] < cur[j][len(cur[j])-1] {
				continue
			}

			tmp := append(cur[j], nums[i])
			cur[curSize] = tmp
			curSize++

			if len(tmp) >= 2 {
				ans = append(ans, tmp)
			}
		}
	}

	return ans
}
