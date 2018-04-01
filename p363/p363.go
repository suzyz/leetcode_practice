func maxSumSubmatrix(matrix [][]int, k int) int {
	n := len(matrix)
	if n == 0 {
		return 0
	}
	m := len(matrix[0])
	if m == 0 {
		return 0
	}

	res := -(1 << 50)
	for i := 0; i < m; i++ { // beginning column
		sum := make([]int, n)
		for j := i; j < m; j++ { // ending column
			for p := 0; p < n; p++ {
				sum[p] += matrix[p][j]
			}

			curSum := 0
			previousSums := make([]int, 1)
			previousSums[0] = 0
			for p := 0; p < n; p++ {
				// binary search
				curSum += sum[p]
				l, r, target := 0, p, curSum-k
				for l < r {
					mid := (r + l) >> 1
					if previousSums[mid] == target {
						l, r = mid, mid
						break
					} else if previousSums[mid] > target {
						r = mid
					} else {
						l = mid + 1
					}
				}
              
				if previousSums[r] >= target {
					res = max(res, curSum-previousSums[r])
				}
               
				// insert curSum
				// Slice!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

				if curSum >= previousSums[p] {
					previousSums = append(previousSums, curSum)
				} else if curSum <= previousSums[0] {
					previousSums = append([]int{curSum}, previousSums...)
				} else {
					l, r = 0, p
					for l < r {
						mid := (r + l) >> 1
						if previousSums[mid] == curSum {
							l, r = mid, mid
							break
						} else if previousSums[mid] > curSum {
							r = mid
						} else {
							l = mid + 1
						}
					}
					
	                tail := append([]int{}, previousSums[l:]...)
					previousSums = append(previousSums[:l], curSum)
					previousSums = append(previousSums, tail...)
				}
			}
		}
	}
	return res
}

func max(i, j int) int {
	if i > j {
		return i
	} else {
		return j
	}
}