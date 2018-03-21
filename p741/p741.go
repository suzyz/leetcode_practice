// DP with space optimization.
// Initially, f[i][j][k] : two persons, starting from (0, 0),
// each took i steps and currently at (j, i-j) and (k, i-k).
// Then I realized that the first dimension is not necessary.

func cherryPickup(grid [][]int) int {
    n := len(grid)
    tot := 2*n-2
    f := make([][]int, n)
    for i := 0; i < n; i++ {
    	f[i] = make([]int, n)
    	for j := 0; j < n; j++ {
    		f[i][j] = -1
    	}
    }
    f[0][0] = grid[0][0]

    for i := 1; i <= tot; i++ {
   		for j := n-1; j >= 0; j-- {
   			for k := n-1; k >= 0; k-- {
   				if i-j < 0 || i-j >= n || i-k < 0 || i-k >= n || grid[j][i-j] == -1 || grid[k][i-k] == -1 {
   					f[j][k] = -1
   					continue
   				}

   				if j > 0 && k > 0 {
   					f[j][k] = max(f[j-1][k-1], f[j][k])
   				}

   				if j > 0 {
   					f[j][k] = max(f[j-1][k], f[j][k])
   				}
   				
   				if k > 0 {
   					f[j][k] = max(f[j][k-1], f[j][k])
   				}

   				if f[j][k] < 0 {
   					continue
   				}

   				if j == k {
   					f[j][k] += grid[j][i-j]
   				} else {
   					f[j][k] += grid[j][i-j] + grid[k][i-k]
   				}
   			}
   		}
   	}

   	return max(f[n-1][n-1], 0)
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}