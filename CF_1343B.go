package main

import (
	"fmt"
)

const MAXN int = 1e5
var even [MAXN]int
var odd [MAXN]int

func solve() {
	var n int 
	fmt.Scanf("%d\n", &n)
	n = n / 2
	if n & 1 == 1 {
		fmt.Println("NO")
		return
	}
	fmt.Println("YES")
	for i := 0; i < n; i += 1 {
		even[i] = 6969690 + 4 * i
		odd[i] = even[i]
		if i & 1 == 1 {
			odd[i] += 1
		} else {
			odd[i] -= 1
		}
	}

	for i := 0; i < n; i += 1 {
		fmt.Printf("%d ", even[i])
	}
	for i := 0; i < n; i += 1 {
		fmt.Printf("%d ", odd[i])
	}
	fmt.Printf("\n")
}


func main() {
	var t int
	fmt.Scanf("%d\n", &t)
	for i := 0; i < t; i += 1 {
		solve()
	}
}