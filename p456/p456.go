package p456

type pair struct {
	min, max int
}

func find132pattern(nums []int) bool {
	n := len(nums)
	if n < 3 {
		return false
	}

	st := []pair{}
	for _, v := range nums {
		if len(st) == 0 || v < st[len(st)-1].min {
			st = append(st, pair{min: v, max: v})
		} else {
			if v == st[len(st)-1].min {
				continue
			}

			if v < st[len(st)-1].max {
				return true
			} else {
				cur := pair{min: st[len(st)-1].min, max: v}
				st = st[:len(st)-1]
				for len(st) > 0 && st[len(st)-1].max <= v {
					st = st[:len(st)-1]
				}
				if len(st) > 0 && v > st[len(st)-1].min {
					return true
				}
				st = append(st, cur)
			}
		}
	}

	return false
}
