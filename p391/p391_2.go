// O(N)
// Think about all the vertices.

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

	const bigNum = 1 << 30
	bottomLeft, topRight := point{bigNum, bigNum}, point{-bigNum, -bigNum}
	tot := 0

	isVertex := make(map[point]bool)

	for _, r := range rectangles {
		bottomLeft.x = min(bottomLeft.x, r[0])
		bottomLeft.y = min(bottomLeft.y, r[1])

		topRight.x = max(topRight.x, r[2])
		topRight.y = max(topRight.y, r[3])

		tot += (r[3] - r[1]) * (r[2] - r[0])

		for i := 0; i < 4; i += 2 {
			for j := 1; j < 4; j += 2 {
				p := point{r[i], r[j]}
				if isVertex[p] {
					delete(isVertex, p)
				} else {
					isVertex[p] = true
				}
			}
		}
	}

	topLeft := point{bottomLeft.x, topRight.y}
	bottomRight := point{topRight.x, bottomLeft.y}

	if len(isVertex) != 4 ||
		!isVertex[topRight] ||
		!isVertex[bottomLeft] ||
		!isVertex[topLeft] ||
		!isVertex[bottomRight] {
		return false
	}

	return tot == (topRight.y-bottomLeft.y)*(topRight.x-bottomLeft.x)
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
