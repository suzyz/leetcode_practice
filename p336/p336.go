// Brutal force.
func palindromePairs(words []string) [][]int {
   	n := len(words)
   	var ans [][]int

   	for i := 0; i < n; i++ {
   		for j := 0; j < n; j++ {
   			if i == j || (len(words[i]) > 0 && len(words[j]) > 0 && words[i][0] != words[j][len(words[j])-1]) {
   				continue
   			}

   			s := words[i] + words[j]
   			if isPalindrome(&s) {
   				ans = append(ans, []int{i, j})
   			}
   		}
   	}
   	return ans
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