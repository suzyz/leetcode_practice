package main

import (
	"fmt"
)

type Interval struct {
	Start int
	End   int
}

type SummaryRanges struct {
	tot    int
	ranges []Interval
}

/** Initialize your data structure here. */
func Constructor() SummaryRanges {
	return SummaryRanges{
		tot:    0,
		ranges: make([]Interval, 0),
	}
}

func (this *SummaryRanges) Addnum(val int) {

	if this.tot == 0 {
		this.tot = 1
		this.ranges = append(this.ranges, Interval{val, val})
		return
	}

	if val == this.ranges[this.tot-1].End+1 {
		this.ranges[this.tot-1].End++
		return
	}

	if val == this.ranges[0].Start-1 {
		this.ranges[0].Start--
		return
	}

	if val > this.ranges[this.tot-1].End+1 {
		this.tot++
		this.ranges = append(this.ranges, Interval{val, val})
		return
	}

	if val < this.ranges[0].Start-1 {
		this.tot++
		this.ranges = append([]Interval{Interval{val, val}}, this.ranges...)
		return
	}

	// find l, s.t. val is in Interval l or just in front of Interval l.
	l, r := 0, this.tot-1
	for l < r {
		mid := l + ((r - l) >> 1)
		if val >= this.ranges[mid].Start && val <= this.ranges[mid].End {
			return
		}

		if val < this.ranges[mid].Start {
			r = mid
		} else {
			l = mid + 1
		}
	}

	if val >= this.ranges[l].Start && val <= this.ranges[l].End {
		return
	}

	if val == this.ranges[l].Start-1 {
		this.ranges[l].Start--
		if l > 0 && (this.ranges[l-1].End == val || this.ranges[l-1].End == val-1) {
			this.tot--

			this.ranges[l-1].End = this.ranges[l].End
			this.ranges = append(this.ranges[:l], this.ranges[l+1:]...)
		}
		return
	}

	if l > 0 && val == this.ranges[l-1].End+1 {
		this.ranges[l-1].End++
		return
	}

	this.tot++
	tail := append([]Interval{Interval{val, val}}, this.ranges[l:]...)
	this.ranges = append(this.ranges[:l], tail...)
}

func (this *SummaryRanges) Getintervals() []Interval {
	return this.ranges
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Addnum(val);
 * param_2 := obj.Getintervals();
 */

func main() {
	obj := Constructor()
	obj.Addnum(1)
	obj.Addnum(3)
	obj.Addnum(7)
	obj.Addnum(2)
	res := obj.Getintervals()
	fmt.Println("res:", res)
}
