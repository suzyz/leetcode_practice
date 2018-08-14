package p765

type unionFind struct {
	numOfGroups int
	fa          []int
}

func (uf *unionFind) getfa(cur int) int {
	if uf.fa[cur] == cur {
		return cur
	}

	uf.fa[cur] = uf.getfa(uf.fa[cur])
	return uf.fa[cur]
}

func (uf *unionFind) union(a, b int) {
	x, y := uf.getfa(a), uf.getfa(b)
	if x != y {
		uf.fa[x] = y
		uf.numOfGroups--
	}
}

func minSwapsCouples(row []int) int {
	n := len(row)

	uf := unionFind{}
	uf.numOfGroups = n / 2
	uf.fa = make([]int, n/2)
	for i := 0; i < n/2; i++ {
		uf.fa[i] = i
	}

	for i := 0; i < n; i += 2 {
		coupleIdx1, coupleIdx2 := row[i]/2, row[i+1]/2
		uf.union(coupleIdx1, coupleIdx2)
	}

	return n/2 - uf.numOfGroups
}
