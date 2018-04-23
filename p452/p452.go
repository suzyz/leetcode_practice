package p452

import (
	"sort"
)

func findMinArrowShots(points [][]int) int {
	n := len(points)

	sort.Slice(points, func(i, j int) bool {
		return points[i][1] < points[j][1]
	})

	i := 0
	res := 0
	for i < n {
		res++

		j := i + 1
		for j < n && points[j][0] <= points[i][1] {
			j++
		}
		i = j
	}
	return res
}
