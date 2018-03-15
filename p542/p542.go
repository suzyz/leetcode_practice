package main

import "fmt"

func main() {
	matrix := [][]int{{0, 1, 0}, {1, 1, 0}, {1, 1, 1}}
	res := updateMatrix(matrix)
	fmt.Println(res)
}

type point struct {
	x, y int
}

var dir []point = []point{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}

func (p *point) add(i int) (res point) {
	return point{p.x + dir[i].x, p.y + dir[i].y}
}

func updateMatrix(matrix [][]int) [][]int {

	n := len(matrix)
	if n == 0 {
		var ans [][]int
		return ans
	}
	m := len(matrix[0])

	ans := make([][]int, n)
	for i := 0; i < n; i++ {
		ans[i] = make([]int, m)
		for j := 0; j < m; j++ {
			if matrix[i][j] == 0 {
				ans[i][j] = 0
			} else {
				ans[i][j] = m + n
			}
		}
	}

	var q []point
	vis := make(map[point]bool)

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if matrix[i][j] == 0 {
				q = append(q, point{i, j})
			}
		}
	}

	for len(q) > 0 {
		var q2 []point
		for len(q) > 0 {
			cur := q[0]
			q = q[1:]

			d := ans[cur.x][cur.y] + 1

			for i := 0; i < 4; i++ {
				next := cur.add(i)
				if next.x < 0 || next.y < 0 || next.x >= n || next.y >= m || vis[next] {
					continue
				}

				if ans[next.x][next.y] > d {
					ans[next.x][next.y] = d

					vis[next] = true
					q2 = append(q2, next)
				}
			}
		}

		if len(q2) == 0 {
			break
		}

		q = make([]point, len(q2))
		copy(q, q2)
	}

	return ans
}
