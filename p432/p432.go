package p432

type bucket struct {
	v         int
	keys      map[string]bool
	pre, next *bucket
}

type AllOne struct {
	head, tail     *bucket
	valueBucketMap map[int]*bucket
	keyValueMap    map[string]int
}

/** Initialize your data structure here. */
func Constructor() AllOne {
	allOne := AllOne{}

	allOne.head, allOne.tail = &bucket{}, &bucket{}
	allOne.head.next = allOne.tail
	allOne.tail.pre = allOne.head

	allOne.valueBucketMap = make(map[int]*bucket)
	allOne.keyValueMap = make(map[string]int)

	return allOne
}

/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
func (this *AllOne) Inc(key string) {
	// fmt.Println(this.keyValueMap)
	if v, ok := this.keyValueMap[key]; ok {
		this.keyValueMap[key]++

		p := this.valueBucketMap[v]
		delete(p.keys, key)

		if p2, ok := this.valueBucketMap[v+1]; ok {
			p2.keys[key] = true
		} else {

			newBucket := &bucket{}
			newBucket.v = v + 1
			newBucket.keys = make(map[string]bool)
			newBucket.keys[key] = true

			this.insertBucketAfter(newBucket, p)
		}

		if len(p.keys) == 0 {
			this.removeBucket(p)
			delete(this.valueBucketMap, v)
		}

	} else {
		this.keyValueMap[key] = 1

		if this.head.next != this.tail && this.head.next.v == 1 {
			this.head.next.keys[key] = true
		} else {
			newBucket := &bucket{}
			newBucket.v = 1
			newBucket.keys = make(map[string]bool)
			newBucket.keys[key] = true

			this.insertBucketAfter(newBucket, this.head)
		}
	}
}

/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
func (this *AllOne) Dec(key string) {
	if v, ok := this.keyValueMap[key]; ok {
		this.keyValueMap[key]--

		p := this.valueBucketMap[v]
		delete(p.keys, key)

		if v > 1 {
			if p2, ok := this.valueBucketMap[v-1]; ok {
				p2.keys[key] = true
			} else {

				newBucket := &bucket{}
				newBucket.v = v - 1
				newBucket.keys = make(map[string]bool)
				newBucket.keys[key] = true

				this.insertBucketAfter(newBucket, p.pre)
			}
		} else {
			delete(this.keyValueMap, key)
		}

		if len(p.keys) == 0 {
			this.removeBucket(p)
			delete(this.valueBucketMap, v)
		}
	}
}

/** Returns one of the keys with maximal value. */
func (this *AllOne) GetMaxKey() string {
	if this.head.next != this.tail {
		for s, _ := range this.tail.pre.keys {
			return s
		}
	}

	return ""
}

/** Returns one of the keys with Minimal value. */
func (this *AllOne) GetMinKey() string {

	if this.head.next != this.tail {
		for s, _ := range this.head.next.keys {
			return s
		}
	}

	return ""
}

func (this *AllOne) insertBucketAfter(newBucket *bucket, pre *bucket) {
	newBucket.pre = pre
	newBucket.next = pre.next
	newBucket.next.pre = newBucket
	pre.next = newBucket

	this.valueBucketMap[newBucket.v] = newBucket
}

func (this *AllOne) removeBucket(p *bucket) {
	p.pre.next = p.next
	p.next.pre = p.pre
}

/**
 * Your AllOne object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Inc(key);
 * obj.Dec(key);
 * param_3 := obj.GetMaxKey();
 * param_4 := obj.GetMinKey();
 */
