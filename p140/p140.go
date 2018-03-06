// Memory Search. 4ms. Same algorithm with the C++ version, but much faster.
func wordBreak(s string, wordDict []string) []string {
    m := make(map[string][]string)

    dict := make(map[string]bool)
    for _, v := range wordDict {
    	dict[v] = true
    }

    m[""] = []string{""}

    dfs(s, &m, &dict)

    return m[s]
}

func dfs(s string, m *map[string][]string, dict *map[string]bool) {
	_, ok := (*m)[s]
	if ok {
		return
	}

	(*m)[s] = []string{}
	if (*dict)[s] == true {
		(*m)[s] = append((*m)[s], s)
	}

	n := len(s)
	for i := 1; i < n; i++ {
		pre := s[:i]

		if (*dict)[pre] == false {
			continue
		}

		rem := s[i:]
		dfs(rem, m, dict)

		for _, suffix := range (*m)[rem] {
			(*m)[s] = append((*m)[s], pre + " " + suffix)
		}
	}
}