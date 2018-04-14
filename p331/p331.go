package p331

import "strings"
import "strconv"

type stack struct {
	top    int
	frames []int
}

func isValidSerialization(preorder string) bool {
	strs := strings.Split(preorder, ",")
	if len(strs) == 0 {
		return false
	}
	if len(strs) == 1 {
		return strs[0] == "#"
	}

	myStack := stack{
		top:    1,
		frames: []int{0},
	}

	for _, s := range strs {
		if myStack.top == 0 {
			return false
		}
		if s == "#" {
			myStack.frames[myStack.top-1]++
			for myStack.top > 0 && myStack.frames[myStack.top-1] == 2 {
				myStack.top--
				myStack.frames = myStack.frames[:myStack.top]
			}
		} else {
			_, err := strconv.Atoi(s)
			if err != nil {
				return false
			}
			myStack.frames[myStack.top-1]++
			myStack.top++
			myStack.frames = append(myStack.frames, 0)
		}
	}

	return myStack.top == 1 && myStack.frames[0] == 1
}
