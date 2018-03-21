// Heap + Greedy. O(N * logN)

import "container/heap"

type project struct {
    profit int
    capital int
}

// projectArr : Array of projects, where all projects are sorted by their capital
type projectArr []*project

func (a projectArr) Len() int {
    return len(a)
}
func (a projectArr) Less(i, j int) bool {
    return a[i].capital < a[j].capital
}
func (a projectArr) Swap(i, j int) {
    a[i], a[j] = a[j], a[i]
}

// projectPQ : Priority queue of projects where the project with the most profit has priority
type projectPQ []*project

// And it implemented heap.Interface :
// type Interface interface {
//     sort.Interface
//     Push(x interface{}) 
//     Pop() interface{}
// }

// 注意接口的Push和Pop方法是供heap包调用的，
// 请使用heap.Push和heap.Pop来向一个堆添加或者删除元素。

func (h projectPQ) Len() int {
    return len(h)
}
func (h projectPQ) Less(i, j int) bool {
    return h[i].profit > h[j].profit
}
func (h projectPQ) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h *projectPQ) Push(x interface{}) {
    entry := x.(*project)
    *h = append(*h, entry)
}
func (h *projectPQ) Pop() interface{} {
    tmp := (*h)[len(*h)-1]
    *h = (*h)[:len(*h)-1]
    return tmp
}

func findMaximizedCapital(k int, W int, Profits []int, Capital []int) int {
    n := len(Profits)

    capAscendingArr := make(projectArr, n)
    for i := 0; i < n; i++ {
        capAscendingArr[i] = &project{
            profit: Profits[i],
            capital: Capital[i],
        }
    }
    sort.Sort(capAscendingArr)

    profitHeap := make(projectPQ, 0, n)

    i := 0
    for {
        for i < n && capAscendingArr[i].capital <= W {
            heap.Push(&profitHeap, capAscendingArr[i])
            i++
        }
        
        if k == 0 || len(profitHeap) == 0 {
            break
        }

        W += heap.Pop(&profitHeap).(*project).profit
        k--
    }

    return W
}
