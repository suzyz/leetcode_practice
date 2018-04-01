
func computeArea(A int, B int, C int, D int, E int, F int, G int, H int) int {
	tot := (D-B)*(C-A) + (H-F)*(G-E)
	top := min(D, H)
	bottom := max(B, F)
    
	if top <= bottom {
		return tot
	}
	left := max(A, E)
	right := min(C, G)

	if left >= right {
		return tot
	}
	overlap := (top - bottom) * (right - left)
    
	return tot - overlap
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}