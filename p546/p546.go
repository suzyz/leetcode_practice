// Plain DFS. TLE.
package p546

func removeBoxes(boxes []int) int {
	n := len(boxes)
	if n < 2 {
		return n
	}

	i, res := 0, n
	for i < n {
		j := i + 1
		for j < n && boxes[j] == boxes[i] {
			j++
		}
		newBoxes := append([]int{}, boxes[:i]...)
		newBoxes = append(newBoxes, boxes[j:]...)
		tmp := removeBoxes(newBoxes) + (j-i)*(j-i)
		if tmp > res {
			res = tmp
		}

		i = j
	}
	return res
}
