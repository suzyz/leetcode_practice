package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	r := Constructor()

	r.Insert(1)
	r.Insert(1)
	r.Insert(2)
	r.Insert(2)
	r.Insert(2)

	fmt.Printf("%v\n", r)
	fmt.Println("remove 1:", r.Remove(1))
	fmt.Printf("%v\n", r)
	fmt.Println("remove 1:", r.Remove(1))
	fmt.Printf("%v\n", r)
	fmt.Println("remove 2:", r.Remove(2))
	fmt.Printf("%v\n", r)

	// r.Insert(1)
	fmt.Println("remove 2:", r.Remove(2))
	fmt.Printf("%v\n", r)
}

// v: value. idx: the index of this number in locations[v]
type pair struct {
	v, idx int
}

type RandomizedCollection struct {
	data      []pair
	locations map[int][]int
}

/** Initialize your data structure here. */
func Constructor() RandomizedCollection {
	rand.Seed(time.Now().UnixNano())

	r := RandomizedCollection{
		data:      make([]pair, 0),
		locations: make(map[int][]int),
	}

	return r
}

/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
func (this *RandomizedCollection) Insert(val int) bool {

	i := len(this.locations[val])
	if i > 0 {
		this.locations[val] = append(this.locations[val], len(this.data))
	} else {
		this.locations[val] = []int{len(this.data)}
	}

	this.data = append(this.data, pair{
		v:   val,
		idx: i,
	})

	return i == 0
}

/** Removes a value from the collection. Returns true if the collection contained the specified element. */
func (this *RandomizedCollection) Remove(val int) bool {
	loc, ok := this.locations[val]
	if !ok {
		return false
	}

	n := len(this.data)
	m := len(loc)
	if n == 1 {
		this.data = []pair{}
		delete(this.locations, val)
	} else {
		last := this.data[n-1]
		this.data[loc[len(loc)-1]] = last
		this.locations[last.v][last.idx] = loc[len(loc)-1]

		this.data = this.data[:n-1]

		if m == 1 {
			delete(this.locations, val)
		} else {
			this.locations[val] = loc[:m-1]
		}
	}

	return true
}

/** Get a random element from the collection. */
func (this *RandomizedCollection) GetRandom() int {
	if len(this.data) == 0 {
		return 0
	}
	i := rand.Intn(len(this.data))
	return this.data[i].v
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
