func getHint(secret string, guess string) string {
    n := len(secret)
    count1 := make([]int, 10)
    count2 := make([]int, 10)

    bull, cow := 0, 0
    for i := 0; i < n; i++ {
    	if secret[i] == guess[i] {
    		bull++
    	} else {
    		count1[secret[i] - '0']++
    		count2[guess[i] - '0']++
    	}
    }

    for i := 0; i < 10; i++ {
    	cow += min(count1[i], count2[i])
    }

    res := strconv.Itoa(bull) + "A" + strconv.Itoa(cow) + "B"
    return res
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
