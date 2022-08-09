package main

import (
	"fmt"
)


func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}


func solve() {
	var n int 
	fmt.Scanf("%d\n", &n)

	var count [3]int
	var inds [3][]int

	for i := 0; i < n; i += 1 {
		var aux int
		fmt.Scanf("%d", &aux);
		aux -= 1
		count[aux] += 1
		inds[aux] = append(inds[aux], i+1)
	}

	var mn int = min(count[0], min(count[1], count[2]))
	fmt.Printf("%d\n", mn)
	for i := 0; i < mn; i += 1 {
		fmt.Printf("%d %d %d\n", inds[0][i], inds[1][i], inds[2][i])
	}

}


func main() {
	var t int = 1
	for i := 0; i < t; i += 1 {
		solve()
	}
}