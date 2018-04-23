package p445

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	n := getLength(l1)
	m := getLength(l2)

	if n < m {
		l1, l2 = l2, l1
		n, m = m, n
	}
	// now n >= m
	p := l1
	for i := 0; i < n-m; i++ {
		p = p.Next
	}

	q := l2
	for p != nil {
		p.Val += q.Val
		p = p.Next
		q = q.Next
	}

	res := &ListNode{
		Val:  0,
		Next: l1,
	}

	var stop *ListNode
	stop = nil
	for {
		p = res
		isCarry := false
		last := stop
		for p.Next != stop {
			if p.Next.Val > 9 {
				p.Next.Val -= 10
				p.Val++

				isCarry = true
				last = p.Next
			}
			p = p.Next
		}
		stop = last

		if !isCarry {
			break
		}
	}

	if res.Val == 0 {
		return res.Next
	} else {
		return res
	}
}

func getLength(p *ListNode) int {
	if p == nil {
		return 0
	}
	return 1 + getLength(p.Next)
}
