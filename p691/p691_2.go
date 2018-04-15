// Search with memoization
package p691

import "strings"

const MAXINT = ((1 << 32) - 2)

func minStickers(stickers []string, target string) int {
	count := make([][]int, len(stickers))
	for i, st := range stickers {
		count[i] = make([]int, 26)
		for _, c := range st {
			count[i][c-'a']++
		}
	}

	f := make(map[string]int)
	f[""] = 0

	dfs(target, count, f)

	if f[target] == MAXINT {
		return -1
	} else {
		return f[target]
	}
}

func dfs(target string, count [][]int, f map[string]int) {
	if _, ok := f[target]; ok {
		return
	}

	f[target] = MAXINT
	targetCount := make([]int, 26)
	for _, c := range target {
		targetCount[c-'a']++
	}

	for _, cur := range count {
		if cur[target[0]-'a'] == 0 {
			continue
		}
		var rem string
		for j := 0; j < 26; j++ {
			if targetCount[j] > cur[j] {
				rem += strings.Repeat(string('a'+j), targetCount[j]-cur[j])
			}
		}
		dfs(rem, count, f)
		f[target] = min(f[target], f[rem]+1)
	}
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
