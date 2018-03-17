func detectCapitalUse(word string) bool {
	n := len(word)
    if n == 0 {
    	return false
    }
    if n == 1 {
    	return true
    }

    firstIsCaptial, secondIsCaptial := true, true
    if word[0] >= 'a' {
    	firstIsCaptial = false
    }
 	if word[1] >= 'a' {
    	secondIsCaptial = false
    }

    if (!firstIsCaptial) && secondIsCaptial {
    	return false
    }

    if secondIsCaptial {
    	for i := 2; i < n; i++ {
    		if word[i] > 'Z' {
    			return false
    		}
    	}
    } else {
    	for i := 2; i < n; i++ {
    		if word[i] < 'a' {
    			return false
    		}
    	}
    }
    
    return true
}
