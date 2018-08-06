// Buckets!
package p220

func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
	if t < 0 || k < 1 {
		return false
	}

	const base = -(1 << 30)

	m := make(map[int]int)
	bucketSize := t + 1

	for i, v := range nums {
		curBucket := (v - base) / bucketSize

		if _, ok := m[curBucket]; ok {
			return true
		}

		if pre, ok := m[curBucket-1]; ok && v-pre <= t {
			return true
		}

		if next, ok := m[curBucket+1]; ok && next-v <= t {
			return true
		}

		if len(m) >= k {
			delete(m, (nums[i-k]-base)/bucketSize)
		}

		m[curBucket] = v
	}

	return false
}
