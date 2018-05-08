package p313

import (
	"container/heap"
)

type node struct {
	v, facIdx int
}

type uglyNums []node

var p []int

func (u uglyNums) Len() int {
	return len(u)
}

func (u uglyNums) Less(i, j int) bool {
	return u[i].v*p[u[i].facIdx] < u[j].v*p[u[j].facIdx]
}

func (u uglyNums) Swap(i, j int) {
	u[i], u[j] = u[j], u[i]
}

func (u *uglyNums) Push(x interface{}) {
	v := x.(node)
	*u = append(*u, v)
}

func (u *uglyNums) Pop() interface{} {
	n := len(*u)
	v := (*u)[n-1]
	*u = (*u)[:n-1]

	return v
}

func nthSuperUglyNumber(n int, primes []int) int {
	if n == 0 {
		return 1
	}

	p = primes

	h := &uglyNums{node{
		v:      1,
		facIdx: 0,
	}}

	m := make(map[int]bool)
	m[1] = true

	res := []int{1}
	k, tot := len(primes), 1
	for tot < n {
		top := heap.Pop(h).(node)
		for len(*h) > 0 && top.facIdx == k {
			top = heap.Pop(h).(node)
		}

		next := node{
			v:      top.v * p[top.facIdx],
			facIdx: 0,
		}

		top.facIdx++
		if top.facIdx < k {
			heap.Push(h, top)
		}

		if m[next.v] {
			continue
		}

		if next.v > res[tot-1] {
			res = append(res, next.v)
		} else {
			j := tot - 1
			for j > 0 && next.v < res[j] {
				j--
			}

			tail := append([]int{}, res[j+1:]...)
			res = append(res[:j+1], next.v)
			res = append(res, tail...)
		}

		heap.Push(h, next)
		m[next.v] = true
		tot++
	}

	return res[len(res)-1]
}
