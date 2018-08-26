package p218

var pos map[int]int
var height []int

type point struct {
	x          int
	isBorderOf int
}

type heap []int

func (h *heap) push(recIdx int) {
	*h = append(*h, recIdx)

	j := len(*h) - 1
	pos[recIdx] = j

	i := j >> 1

	for i > 0 {
		if height[(*h)[i]] < height[(*h)[j]] {
			pos[(*h)[i]], pos[(*h)[j]] = pos[(*h)[j]], pos[(*h)[i]]
			(*h)[i], (*h)[j] = (*h)[j], (*h)[i]

			j = i
			i = j >> 1
		} else {
			return
		}
	}
}

func (h *heap) del(id int) {
	n := len(*h)
	if pos[id] == n-1 {
		(*h) = (*h)[:n-1]
	} else {
		pos[(*h)[n-1]] = pos[id]
		(*h)[pos[id]] = (*h)[n-1]

		(*h) = (*h)[:n-1]
		n--

		i := pos[id]
		j := i << 1
		for j < n {
			k := i
			if height[(*h)[j]] > height[(*h)[k]] {
				k = j
			}
			if j+1 < n && height[(*h)[j+1]] > height[(*h)[k]] {
				k = j + 1
			}

			if k == i {
				break
			}

			pos[(*h)[i]], pos[(*h)[k]] = pos[(*h)[k]], pos[(*h)[i]]
			(*h)[i], (*h)[k] = (*h)[k], (*h)[i]

			i = k
			j = i << 1
		}
	}

	delete(pos, id)
}

func getSkyline(buildings [][]int) [][]int {
	n := len(buildings)
	res := make([][]int, 0)
	if n == 0 {
		return res
	}

	points := make([]point, 0)
	pos = make(map[int]int)
	height = make([]int, n+1)

	for i := 0; i < n; i++ {
		height[i] = buildings[i][2]

		points = append(points, point{
			x:          buildings[i][0],
			isBorderOf: i + 1,
		})

		points = append(points, point{
			x:          buildings[i][1],
			isBorderOf: -i - 1,
		})
	}

	sort.Slice(points, func(i, j int) bool {
		return points[i].x < points[j].x
	})

	h := &heap{1, n}

	for _, p := range points {
		if p.isBorderOf > 0 { // at left border

			h.push(p.isBorderOf - 1)

		} else { // at right border

			h.del(-p.isBorderOf - 1)
		}

		res = append(res, []int{p.x, height[(*h)[1]]})
	}

	tot := 0
	for i := 1; i < len(res); i++ {
		if res[i][0] != res[tot][0] {
			tot++
		}
		res[tot] = res[i]
	}

	res = res[:tot+1]

	tot = 0
	for i := 0; i < len(res); i++ {
		if res[i][1] != res[tot][1] {
			tot++

			res[tot] = res[i]
		}
	}

	res = res[:tot+1]

	return res
}
