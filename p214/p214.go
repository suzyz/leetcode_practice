func shortestPalindrome(s string) string {
    n := len(s)
    for i := n; i >= 0; i-- {
    	left := s[:i]

    	if (isPalindrome(&left)) {
    		right := s[i:]
    		tmp := reverse(&right)
    		return tmp + s
    	}
    }

    return ""
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