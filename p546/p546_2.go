// DP.

package p546

const maxn = 102

func removeBoxes(boxes []int) int {
	n := len(boxes)
	if n < 2 {
		return n
	}

	var f [maxn][maxn][maxn]int

	for l := 1; l <= n; l++ {
		for en := l - 1; en < n; en++ {
			st := en - l + 1

			for k := 0; k <= st; k++ {
				f[st][en][k] = (k+1)*(k+1) + f[st+1][en][0]

				for m := st + 1; m <= en; m++ {
					if boxes[m] == boxes[st] {
						f[st][en][k] = max(f[st][en][k], f[st+1][m-1][0]+f[m][en][k+1])
					}
				}
			}
		}
	}

	return f[0][n-1][0]
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
