func ladderLength(beginWord string, endWord string, wordList []string) int {

	dist := make(map[string]int)
	maxdist := len(wordList)

   	for _, s := range wordList {
   		dist[s] = maxdist
   	}

   	if _, ok := dist[endWord]; !ok {
   		return 0
   	}

   	n := len(beginWord)

   	dist[beginWord] = 1
   	q := []string{beginWord}
  	
  	for ; len(q) > 0; {
  		s := []byte(q[0])
  		newDist := dist[q[0]] + 1
  		q = q[1:]

  		for i := 0; i < n; i++ {
  			origin := rune(s[i])
  			for j := 'a'; j <= 'z'; j++ {
  				if j != origin {
					s[i] = byte(j)

					tmp := string(s)

  					if tmp == endWord {
  						return newDist
  					}

  					if newDist < dist[tmp] {
  						dist[tmp] = newDist
  						q = append(q,tmp)
  					}
  				}
  			}

  			s[i] = byte(origin)
  		}
  	}

   	return 0
}
