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

func main() {
	var n, k int
	var good_count int = 0
	fmt.Scanf("%d %d\n", &n, &k)
	for i := 0; i < n; i += 1 {
		var aux int
		fmt.Scanf("%d", &aux);
		if 5 - aux >= k {
			good_count += 1
		}
	}
	fmt.Println(good_count / 3)
}