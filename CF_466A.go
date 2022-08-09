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
	var n, m, a, b int
	fmt.Scanf("%d %d %d %d\n", &n, &m, &a, &b)
	b = min(b, m * a)
	fmt.Println(n / m * b + min(n % m * a, b))
}