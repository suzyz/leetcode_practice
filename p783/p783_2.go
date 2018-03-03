// Using channal without buffer.

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func traverse(p *TreeNode, f func(*TreeNode)) {
	if p == nil {
		return
	}

	traverse(p.Left, f)
	f(p)
	traverse(p.Right, f)
}

func traverseWithChannel(p *TreeNode) (chan int) {
	c := make(chan int)

    go func () {
        traverse(p, func(node *TreeNode) { c <- node.Val })

        close(c)   
    } ()

	return c
}

func minDiffInBST(root *TreeNode) int {
    
    c := traverseWithChannel(root)

    isFirst := true
    lastVal, ans := 0, 200000000
    for v := range c {
    	if isFirst {
    		isFirst = false
    	} else {
    		if v - lastVal < ans {
    			ans = v - lastVal
    		}
    	}
    	lastVal = v
    }

    return ans
}
