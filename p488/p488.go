// TLE.
func findMinStep(board string, hand string) int {

	m := len(hand)

	for i := 1; i <= m; i++ {
		
		used := make([]bool, m)
		if try(0, i, m, used, &hand, board) {
			return i
		}
	}
    
	return -1
}

func try(i, tot, lim int, used []bool, hand *string, board string) bool {
    
	if i == tot {
		if shrink(board) == "" {
			return true
		} else {
			return false
		}
	}

	for k := 0; k < lim; k++ {
		if !used[k] {
			used[k] = true
			for j := 0; j <= len(board); j++ {
				t := board[:j] + string((*hand)[k]) + board[j:]
				t = shrink(t)

				if try(i+1, tot, lim, used, hand, t) {
					return true
				}
			}
			used[k] = false		
		}
	}

	return false
}

func shrink(s string) string {
	n := len(s)
	if n == 0 {
		return ""
	}
	if n < 3 {
		return s
	}

	for i := 0; i < n-2; i++ {
		if s[i] == s[i+1] && s[i] == s[i+2] {
			j := i + 3
			for j < n && s[j] == s[i] {
				j++
			}
			t := s[:i] + s[j:]
			return shrink(t)
		}
	}
	return s
}
