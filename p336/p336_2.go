// Construct and compare. Using map.
func palindromePairs(words []string) [][]int {
   	n := len(words)
    m := make(map[string]int)
   	var ans [][]int

   	for i, w := range words {
   		m[w] = i
   	}

    for i := 0; i < n; i++ {
        l := len(words[i])

        for j := 0; j <= l; j++ {
            left := words[i][:j]
            right := words[i][j:]

            if j > 0 && isPalindrome(&left) {
                tmp := reverse(&right)
                if idx, ok := m[tmp]; ok && idx != i {
                    ans = append(ans, []int{idx, i})
                }
            }

            if isPalindrome(&right) {
                tmp := reverse(&left)
                if idx, ok := m[tmp]; ok && idx != i {
                    ans = append(ans, []int{i, idx})
                }
            }
        }
    }

   	return ans
}

func reverse(p *string) string {
    n := len(*p)
    bytes := make([]byte, n)
    for i := 0; i < n; i++ {
        bytes[i] = (*p)[n-1-i]
    }
    return string(bytes)
}

func isPalindrome(p *string) bool {
    i, j := 0, len(*p) - 1
    for i < j {
        if (*p)[i] != (*p)[j] {
            return false
        }
        i++
        j--
    }
    return true
}

