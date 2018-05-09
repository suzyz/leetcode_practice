// Stack.
package p726

func countOfAtoms(formula string) string {
	count := helper([]byte(formula))

	type atom struct {
		name  string
		count int
	}

	atoms := []atom{}
	for k, v := range count {
		atoms = append(atoms, atom{
			name:  k,
			count: v,
		})
	}

	sort.Slice(atoms, func(i, j int) bool {
		return atoms[i].name < atoms[j].name
	})

	res := ""
	for _, a := range atoms {
		res += a.name
		if a.count > 1 {
			res += strconv.Itoa(a.count)
		}
	}

	return res
}

func helper(s []byte) map[string]int {
	n := len(s)

	st := make([]map[string]int, 0)
	st = append(st, make(map[string]int))
	i := 0
	for i < n {
		if s[i] == '(' {
			newMap := make(map[string]int)
			st = append(st, newMap)
			i++
		} else if s[i] == ')' {
			last := len(st) - 1
			i++

			num := 0
			if i == n || s[i] < '0' || s[i] > '9' {
				num = 1
			} else {
				for i < n && s[i] >= '0' && s[i] <= '9' {
					num = 10*num + int(s[i]) - '0'
					i++
				}
			}

			for k, v := range st[last] {
				st[last-1][k] += v * num
			}

			st = st[:last]

		} else { // s[i] is a letter
			cur := string(s[i])
			i++
			for i < n && s[i] >= 'a' && s[i] <= 'z' {
				cur += string(s[i])
				i++
			}

			if i == n || s[i] > '9' || s[i] < '0' {
				st[len(st)-1][cur]++
				continue
			}

			num := 0
			for i < n && s[i] >= '0' && s[i] <= '9' {
				num = 10*num + int(s[i]) - '0'
				i++
			}
			st[len(st)-1][cur] += num
		}
	}
	return st[0]
}
