package p709

func toLowerCase(str string) string {

	res := ""
	for _, c := range str {
		if c >= 'A' && c <= 'Z' {
			res += string('a' - 'A' + c)
		} else {
			res += string(c)
		}
	}

	return res
}
