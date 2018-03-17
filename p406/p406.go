func reconstructQueue(people [][]int) [][]int {
    n := len(people)

    sort.Slice(people, func(i, j int) bool {
    		return people[i][0] > people[j][0] || 
    		(people[i][0] == people[j][0] && people[i][1] < people[j][1])
    	})

    var ans [][]int
    if (n == 0) {
    	return ans
    }

    ans = append(ans, make([]int, 2))
    copy(ans[0], people[0])

    for i := 1; i < n; i++ {
    	count := 0

    	j := 0
    	for ; j < i; j++ {
    		if count == people[i][1] {
    				break
    		}

    		if ans[j][0] >= people[i][0] {
    			count++
    		}
    	}

    	if j == i {
    		ans = append(ans, people[i])
    	} else {
    		rem := append([][]int{}, ans[j:]...) 
    		ans = append(ans[:j], people[i])
    		ans = append(ans, rem...)
    	}
    }

    return ans
}
