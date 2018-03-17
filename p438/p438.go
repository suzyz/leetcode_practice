func findAnagrams(s string, p string) []int {
	var ans []int
	if len(s) < len(p) {
		return ans
	}

	const size = 26
	lenp := len(p)
	count1 := make([]int, size)
	count2 := make([]int, size)
	for _, c := range p {
		count1[c - 'a']++
	}

	var flag bool
    for i, c := range s {
    	count2[c - 'a']++
    	if i >= lenp {
    		count2[s[i-lenp] - 'a']--
    	}

    	flag = true
    	for j := 0; j < size; j++ {
    		if count1[j] != count2[j] {
    			flag = false
    			break
    		}
    	}
    	if flag {
    		ans = append(ans, i-lenp+1)
    	}
    }
    
    return ans
}
