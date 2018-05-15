package p791

func customSortString(S string, T string) string {
	m := make(map[byte][]byte)
	s := []byte(S)
	t := []byte(T)

	for _, c := range t {
		if len(m[c]) == 0 {
			m[c] = make([]byte, 1)
			m[c][0] = c
		} else {
			m[c] = append(m[c], c)
		}
	}

	res := []byte{}
	for _, c := range s {
		if len(m[c]) > 0 {
			res = append(res, m[c]...)
			delete(m, c)
		}
	}

	for _, v := range m {
		res = append(res, v...)
	}
	return string(res)
}
