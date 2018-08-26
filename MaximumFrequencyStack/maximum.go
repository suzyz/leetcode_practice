package MaximumFrequencyStack

type Num struct {
	num, count, index int
	enterStackTimes   *[]int
}

type PriorityQueue []*Num

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	if pq[i].count == pq[j].count {
		l1 := len(*pq[i].enterStackTimes)
		l2 := len(*pq[j].enterStackTimes)
		if l1 == 0 {
			return false
		}
		if l2 == 0 {
			return true
		}
		return (*pq[i].enterStackTimes)[l1-1] > (*pq[j].enterStackTimes)[l2-1]
	}
	return pq[i].count > pq[j].count
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	Num := x.(*Num)
	Num.index = n
	*pq = append(*pq, Num)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	Num := old[n-1]
	Num.index = -1
	*pq = old[0 : n-1]
	return Num
}

func (pq *PriorityQueue) updateAdd(Num *Num, newTime int) {

	Num.count++
	*Num.enterStackTimes = append(*Num.enterStackTimes, newTime)

	heap.Fix(pq, Num.index)
}

func (pq *PriorityQueue) updateSub(Num *Num) {

	Num.count--
	n := len(*Num.enterStackTimes)
	*Num.enterStackTimes = (*Num.enterStackTimes)[:n-1]

	heap.Fix(pq, Num.index)
}

////

type FreqStack struct {
	myTime int

	pq  PriorityQueue
	pos map[int]*Num
}

func Constructor() FreqStack {
	f := FreqStack{}
	f.myTime = 0
	f.pq = make(PriorityQueue, 0)
	f.pos = make(map[int]*Num)

	return f
}

func (this *FreqStack) Push(x int) {
	this.myTime++

	if _, ok := this.pos[x]; ok {
		this.pq.updateAdd(this.pos[x], this.myTime)
	} else {
		newNum := &Num{
			index:           len(this.pos),
			num:             x,
			count:           1,
			enterStackTimes: &[]int{this.myTime},
		}

		heap.Push(&this.pq, newNum)
		this.pos[x] = newNum
	}
}

func (this *FreqStack) Pop() int {
	res := this.pq[0].num

	if this.pq[0].count == 1 {
		heap.Pop(&this.pq)
		delete(this.pos, res)
	} else {
		this.pq.updateSub(this.pos[res])
	}

	return res
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 */
