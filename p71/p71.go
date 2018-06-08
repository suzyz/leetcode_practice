package p71

import (
	"strings"
)

func simplifyPath(path string) string {
	strs := strings.Split(path, "/")
	st := []string{}

	for _, s := range strs {
		if len(s) == 0 || s == "." {
			continue
		}

		if s == ".." {
			if len(st) > 0 {
				st = st[:len(st)-1]
			}
		} else {
			st = append(st, s)
		}
	}

	return "/" + strings.Join(st, "/")
}
