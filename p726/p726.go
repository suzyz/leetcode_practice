// Recursion.
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
	count := make(map[string]int)

	i := 0
	for i < n {
		if s[i] == '(' {
			j := i + 1
			level := 1
			for j < n {
				if s[j] == '(' {
					level++
				} else if s[j] == ')' {
					level--
					if level == 0 {
						break
					}
				}
				j++
			}

			m := helper(s[i+1 : j])
			j++
			num := 0
			for j < n && s[j] >= '0' && s[j] <= '9' {
				num = 10*num + int(s[j]) - '0'
				j++
			}

			for k, v := range m {
				count[k] += v * num
			}

			i = j
		} else {
			cur := string(s[i])
			j := i + 1
			for j < n && s[j] >= 'a' && s[j] <= 'z' {
				cur += string(s[j])
				j++
			}
			i = j
			if i == n || s[i] > '9' || s[i] < '0' {
				count[cur]++
				continue
			}

			j = i
			num := 0
			for j < n && s[j] >= '0' && s[j] <= '9' {
				num = 10*num + int(s[j]) - '0'
				j++
			}
			count[cur] += num
			i = j
		}
	}
	return count
}
