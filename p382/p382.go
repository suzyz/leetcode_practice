package p382

import (
	"math/rand"
	"time"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

type Solution struct {
	head *ListNode
}

/** @param head The linked list's head.
  Note that the head is guaranteed to be not null, so it contains at least one node. */
func Constructor(head *ListNode) Solution {
	rand.Seed(time.Now().UnixNano())
	return Solution{head}
}

/** Returns a random node's value. */
func (this *Solution) GetRandom() int {
	cur := this.head
	if cur == nil {
		return 0
	}
	if cur.Next == nil {
		return cur.Val
	}

	i := 1
	v := cur.Val
	for cur.Next != nil {
		i++
		cur = cur.Next

		tmp := rand.Intn(i)
		if tmp == 0 {
			v = cur.Val
		}
	}
	return v
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(head);
 * param_1 := obj.GetRandom();
 */
