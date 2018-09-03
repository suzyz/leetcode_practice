package p1

func isMonotonic(A []int) bool {
	if len(A) <= 2 {
		return true
	}

	flagInc, flagDec := false, false

	for i := 1; i < len(A); i++ {
		if A[i] > A[i-1] {
			if flagDec {
				return false
			}
			flagInc = true
		} else if A[i] < A[i-1] {
			if flagInc {
				return false
			}
			flagDec = true
		}
	}

	return true
}
