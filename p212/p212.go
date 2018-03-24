// DFS with Trie.
package main

func main() {

}

type node struct {
	isWord bool
	word   string
	next   [26]*node
}

type trie struct {
	root *node
}

func (t *trie) insert(w string) {
	cur := t.root
	for _, c := range w {
		if cur.next[int(c)-'a'] == nil {
			cur.next[int(c)-'a'] = &node{}
		}
		cur = cur.next[int(c)-'a']
	}
	cur.isWord = true
	cur.word = w
}

type point struct {
	x, y int
	loc  *node
}

var dir = [4]point{point{0, 1, nil}, point{0, -1, nil}, point{1, 0, nil}, point{-1, 0, nil}}

func (p point) add(i int) point {
	return point{p.x + dir[i].x, p.y + dir[i].y, nil}
}

func findWords(board [][]byte, words []string) []string {
	n := len(board)
	var ans []string
	if n == 0 {
		return ans
	}
	m := len(board[0])
	if m == 0 {
		return ans
	}

	t := &trie{}
	t.root = &node{}
	for _, w := range words {
		if len(w) > 0 {
			t.insert(w)
		} else {
			ans = append(ans, w)
		}
	}

	vis := make([][]bool, n)
	for i := 0; i < n; i++ {
		vis[i] = make([]bool, m)
	}

	isFound := make(map[string]bool)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if t.root.next[int(board[i][j])-'a'] == nil {
				continue
			}

			vis[i][j] = true
			dfs(point{i, j, t.root.next[int(board[i][j])-'a']}, n, m, board, vis, isFound)
			vis[i][j] = false
		}
	}

	for k := range isFound {
		ans = append(ans, k)
	}

	return ans
}

func dfs(p point, n, m int, board [][]byte, vis [][]bool, isFound map[string]bool) {
	if p.loc.isWord {
		isFound[p.loc.word] = true
	}

	for i := 0; i < 4; i++ {
		next := p.add(i)
		if next.x < 0 || next.x >= n || next.y < 0 || next.y >= m || vis[next.x][next.y] {
			continue
		}

		c := board[next.x][next.y]
		if p.loc.next[int(c)-'a'] == nil {
			continue
		}

		vis[next.x][next.y] = true
		dfs(point{next.x, next.y, p.loc.next[int(c)-'a']}, n, m, board, vis, isFound)
		vis[next.x][next.y] = false
	}
}
