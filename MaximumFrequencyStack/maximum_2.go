// Using a series of stacks.
// Much easier to think and implement.
package MaximumFrequencyStack

type stack []int

type FreqStack struct {
	stacks  map[int]stack
	freq    map[int]int
	maxFreq int
}

func Constructor() FreqStack {
	f := FreqStack{}
	f.stacks = make(map[int]stack)
	f.freq = make(map[int]int)

	return f
}

func (this *FreqStack) Push(x int) {
	this.freq[x]++

	newFreq := this.freq[x]

	if this.stacks[newFreq] == nil { /// ????
		this.stacks[newFreq] = stack{x}
	} else {
		this.stacks[newFreq] = append(this.stacks[newFreq], x)
	}

	if newFreq > this.maxFreq {
		this.maxFreq = newFreq
	}
}

func (this *FreqStack) Pop() int {

	n := len(this.stacks[this.maxFreq])
	res := this.stacks[this.maxFreq][n-1]

	this.stacks[this.maxFreq] = this.stacks[this.maxFreq][:n-1]
	this.freq[res]--

	if n == 1 {
		this.maxFreq--
	}

	return res
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 */
