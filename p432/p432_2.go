// Only use one map in AllOne.
package p432

type bucket struct {
	v         int
	keys      map[string]bool
	pre, next *bucket
}

type AllOne struct {
	head, tail   *bucket
	keyBucketMap map[string]*bucket
}

/** Initialize your data structure here. */
func Constructor() AllOne {
	allOne := AllOne{}

	allOne.head, allOne.tail = &bucket{}, &bucket{}
	allOne.head.next = allOne.tail
	allOne.tail.pre = allOne.head

	allOne.keyBucketMap = make(map[string]*bucket)

	return allOne
}

/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
func (this *AllOne) Inc(key string) {

	if p, ok := this.keyBucketMap[key]; ok {

		delete(p.keys, key)

		if p.next != this.tail && p.next.v == p.v+1 {
			p.next.keys[key] = true
			this.keyBucketMap[key] = p.next
		} else {

			newBucket := &bucket{}
			newBucket.v = p.v + 1
			newBucket.keys = make(map[string]bool)
			newBucket.keys[key] = true

			this.insertBucketAfter(newBucket, p)
			this.keyBucketMap[key] = newBucket
		}

		if len(p.keys) == 0 {
			this.removeBucket(p)
		}

	} else {

		if this.head.next != this.tail && this.head.next.v == 1 {
			this.head.next.keys[key] = true
			this.keyBucketMap[key] = this.head.next
		} else {
			newBucket := &bucket{}
			newBucket.v = 1
			newBucket.keys = make(map[string]bool)
			newBucket.keys[key] = true

			this.insertBucketAfter(newBucket, this.head)
			this.keyBucketMap[key] = newBucket
		}
	}
}

/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
func (this *AllOne) Dec(key string) {
	if p, ok := this.keyBucketMap[key]; ok {

		delete(p.keys, key)

		if p.v > 1 {
			if p.pre != this.head && p.pre.v == p.v-1 {
				p.pre.keys[key] = true
				this.keyBucketMap[key] = p.pre
			} else {

				newBucket := &bucket{}
				newBucket.v = p.v - 1
				newBucket.keys = make(map[string]bool)
				newBucket.keys[key] = true

				this.insertBucketAfter(newBucket, p.pre)
				this.keyBucketMap[key] = newBucket
			}
		} else {
			delete(this.keyBucketMap, key)
		}

		if len(p.keys) == 0 {
			this.removeBucket(p)
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
