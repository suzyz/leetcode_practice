// O(N*logN + N^2). Brutal force.

package main

import (
	"fmt"
	"sort"
)

func main() {

}

type point struct {
	x, y int
}

func isRectangleCover(rectangles [][]int) bool {
	n := len(rectangles)

	sort.Slice(rectangles, func(i, j int) bool {
		return rectangles[i][0] < rectangles[j][0]
	})

	for i := 0; i < n; i++ {
		r1 := rectangles[i]
		for j := 0; j < n; j++ {
			if j == i || rectangles[j][2] < r1[0] || rectangles[j][1] > r1[3] || rectangles[j][3] < r1[1] {
				continue
			}

			r2 := rectangles[j]

			if r2[0] > r1[2] {
				break
			}

			if isInRec(r1, r2[0], r2[1]) || isInRec(r1, r2[2], r2[3]) || isInRec(r1, r2[0], r2[3]) || isInRec(r1, r2[2], r2[1]) {
				return false
			}

			// top
			if r1[3] == r2[3] {
				if r1[2] > r2[0] && r1[2] <= r2[2] {
					return false
				}
			}

			// bottom
			if r1[1] == r2[1] {
				if r1[2] > r2[0] && r1[2] <= r2[2] {
					return false
				}
			}

			// left
			if r1[0] == r2[0] {
				if r1[3] > r2[1] && r1[3] <= r2[3] {
					return false
				}
			}

			// right
			if r1[2] == r2[2] {
				if r1[3] > r2[1] && r1[3] <= r2[3] {
					return false
				}
			}
		}
	}

	const bigNum = 1 << 30
	bottomLeft, topRight := point{bigNum, bigNum}, point{-bigNum, -bigNum}
	tot := 0

	for _, r := range rectangles {
		bottomLeft.x = min(bottomLeft.x, r[0])
		bottomLeft.y = min(bottomLeft.y, r[1])

		topRight.x = max(topRight.x, r[2])
		topRight.y = max(topRight.y, r[3])

		tot += (r[3] - r[1]) * (r[2] - r[0])
	}

	return tot == (topRight.y-bottomLeft.y)*(topRight.x-bottomLeft.x)
}

func isInRec(r []int, x, y int) bool {
	if x > r[0] && x < r[2] && y > r[1] && y < r[3] {
		return true
	} else {
		return false
	}
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
