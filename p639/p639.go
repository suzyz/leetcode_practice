// Plain DP.
func numDecodings(s string) int {
	const mo = 1e9+7

	n := len(s)
	if n == 0 || s[0] == '0' {
		return 0
	}

	for i := 1; i < n; i++ {
		if s[i] == '0' {
			if s[i-1] != '1' && s[i-1] != '2' && s[i-1] != '*' {
				return 0
			}
		}
	}

	f := make([]int, n)
	if s[0] == '*' {
		f[0] = 9
	} else {
		f[0] = 1
	}

	var a int // a == f[i-2]
	for i := 1; i < n; i++ {
		if i == 1 {
			a = 1
		} else {
			a = f[i-2]
		}

		if s[i] == '*' {
			f[i] = 9*f[i-1]%mo

			switch s[i-1] {
			case '*':
				f[i] += 15*a%mo
			case '1':
				f[i] += 9*a%mo
			case '2':
				f[i] += 6*a%mo
			}
		} else if s[i] == '0' {	
			if s[i-1] == '*' {
				f[i] = 2*a
			} else { // s[i-1] == '1' or '2'
				f[i] = a
			}
		} else { // s[i] != '0' && s[i] != '*'
			f[i] = f[i-1]
			if s[i-1] == '*' {
				// * -> 1
				f[i] += a
				
				// * -> 2
				if s[i] <= '6' {
					f[i] += a
				}
			} else if s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6') {
				f[i] += a
			}
		}

		f[i] %= mo
	}

	return f[n-1]
}
