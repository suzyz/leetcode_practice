// Bidirectional BFS
package main

import (
	"fmt"
	"sort"
)

func main() {
	//res := findLadders("hit", "cog", []string{"hot", "dot", "dog", "lot", "log", "cog"})
	res := findLadders("red", "tax", []string{"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"})
	fmt.Println("res:")
	fmt.Println(res)
}

func findLadders(beginword string, endword string, wordList []string) [][]string {
	dict := make(map[string]bool)
	for _, s := range wordList {
		dict[s] = true
	}

	var ans [][]string

	if !dict[endword] {
		return ans
	}

	words1 := make(map[string]bool)
	words2 := make(map[string]bool)
	words1[beginword], words2[endword] = true, true

	curPath := []string{beginword}
	nexts := make(map[string][]string)

	words1IsBegin := false

	if helper(words1, words2, dict, nexts, &words1IsBegin) {
		for k := range nexts {
			sort.Slice(nexts[k], func(i, j int) bool {
				return nexts[k][i] < nexts[k][j]
			})
		}

		getPath(beginword, endword, nexts, curPath, &ans)
	}

	return ans
}

func helper(words1, words2, dict map[string]bool, nexts map[string][]string, words1IsBegin *bool) bool {

	*words1IsBegin = !(*words1IsBegin)

	if len(words1) == 0 {
		return false
	}

	if len(words1) > len(words2) {
		return helper(words2, words1, dict, nexts, words1IsBegin)
	}

	for k := range words1 {
		delete(dict, k)
	}

	for k := range words2 {
		delete(dict, k)
	}

	words3 := make(map[string]bool)
	done := false

	for cur := range words1 {
		buff := []rune(cur)
		n := len(cur)

		for i := 0; i < n; i++ {
			for j := 'a'; j <= 'z'; j++ {
				if j == rune(cur[i]) {
					continue
				}

				buff[i] = j
				newWord := string(buff)

				if words2[newWord] {
					done = true

					if *words1IsBegin {
						nexts[cur] = append(nexts[cur], newWord)
					} else {
						nexts[newWord] = append(nexts[newWord], cur)
					}
				} else if (!done) && dict[newWord] {
					words3[newWord] = true

					if *words1IsBegin {
						nexts[cur] = append(nexts[cur], newWord)
					} else {
						nexts[newWord] = append(nexts[newWord], cur)
					}
				}
			}
			buff[i] = rune(cur[i])
		}
	}

	return done || helper(words2, words3, dict, nexts, words1IsBegin)
}

func getPath(beginword, endword string, nexts map[string][]string, curPath []string, ans *[][]string) {

	if beginword == endword {
		path := make([]string, len(curPath))
		copy(path, curPath)
		*ans = append(*ans, path)
		return
	}

	for i, s := range nexts[beginword] {
		if i > 0 && s == nexts[beginword][i-1] {
			continue
		}
		curPath = append(curPath, s)
		getPath(s, endword, nexts, curPath, ans)
		curPath = curPath[0 : len(curPath)-1]
	}
}
