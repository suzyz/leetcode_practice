// Sort + Plain DP. O(N^2). Very slow.
type Task [][]int

func (t Task) Len() int {
	return len(t)
}

func (t Task) Less(i, j int) bool {
	return t[i][1] < t[j][1] || (t[i][1] == t[j][1] && t[i][0] > t[j][0])
}

func (t Task) Swap(i, j int) {
	t[i], t[j] = t[j], t[i]
}

func findMaximizedCapital(k int, W int, Profits []int, Capital []int) int {
    n := len(Profits)

    p := make([][]int, n)
    for i := 0; i < n; i++ {
    	p[i] = []int{Profits[i], Capital[i]}
    }

    sort.Sort(Task(p))

    f := make([][]int, 2)
    f[0] = make([]int, n+1)
    f[1] = make([]int, n+1)
    f[0][0], f[1][0] = W, W

   	flag := 1
   	if k > n {
   		k = n
   	}
   	for i := 1; i <= n; i++ {
   		//f[flag][0] = W
   		for j := 1; j <= k && j <= i; j++ {
   			if j < i {
   				f[flag][j] = f[1-flag][j]
   			}

   			if f[1-flag][j-1] >= p[i-1][1] {
   				tmp := f[1-flag][j-1] + p[i-1][0]
   				if tmp > f[flag][j] {
   					f[flag][j] = tmp
   				}
   			}
   		}
   		flag = 1-flag
   	}

   	ans := 0
   	flag = 1-flag
   	for i := 0; i <= k; i++ {
   		if f[flag][i] > ans {
   			ans = f[flag][i]
   		}
   	}

   	return ans
}
