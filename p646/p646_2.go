// Sort + Greedy. O(n^2)

type Pair [][]int

func (p Pair) Len() int {
    return len(p)
}

// Greedy!
func (p Pair) Less(i, j int) bool {
    return p[i][1] < p[j][1]
}

func (p Pair) Swap(i, j int) {
    p[i], p[j] = p[j], p[i]
}

func findLongestChain(pairs [][]int) int {
    n := len(pairs)
    if n < 2 {
    	return n
    }

    sort.Sort(Pair(pairs))

    ans, i, end := 0, 0, 0

    for i < n {
        ans++
        end = pairs[i][1]
        
        for i < n && pairs[i][0] <= end {
            i++
        }
    }

    return ans
}
