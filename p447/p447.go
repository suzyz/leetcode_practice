// Plain. O(N^3) time, O(N^2) space.
package p447

func numberOfBoomerangs(points [][]int) int {
	n, count := len(points), 0

	dist2 := make([][]float64, n)
	for i := 0; i < n; i++ {
		dist2[i] = make([]float64, n)
	}

	for i := 0; i < n-1; i++ {

		xi := points[i][0]
		yi := points[i][1]

		for j := i + 1; j < n; j++ {
			dist2[i][j] = float64(xi-points[j][0])*float64(xi-points[j][0]) +
				float64(yi-points[j][1])*float64(yi-points[j][1])

			dist2[j][i] = dist2[i][j]
		}
	}

	for i := 0; i < n; i++ {

		for j := 0; j < n-1; j++ {
			if j == i {
				continue
			}

			for k := j + 1; k < n; k++ {
				if k == i {
					continue
				}

				if math.Abs(dist2[i][j]-dist2[i][k]) < 1e-8 {
					count++
				}
			}
		}
	}

	count <<= 1
	return count
}
