// Using map. Count permutations. O(N^2) time, O(N) space.
package p447

func numberOfBoomerangs(points [][]int) int {
	n, count := len(points), 0

	for i := 0; i < n; i++ {
		m := make(map[int64]int, n)

		xi := points[i][0]
		yi := points[i][1]

		for j := 0; j < n; j++ {
			dist2 := int64(xi-points[j][0])*int64(xi-points[j][0]) +
				int64(yi-points[j][1])*int64(yi-points[j][1])

			m[dist2]++
		}

		for _, v := range m {
			count += v * (v - 1)
		}
	}

	return count
}
