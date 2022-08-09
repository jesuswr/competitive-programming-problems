package main

import (
    "fmt"
)


func main() {
    var n, a, b, c int
    fmt.Scanf("%d %d %d %d\n", &n, &a, &b, &c)
    var dp [4001]int
    dp[0] = 0
    for i := 1; i < 4001; i += 1 {
        dp[i] = -100000
        if i >= a && dp[i] < dp[i-a] + 1 {
            dp[i] = dp[i-a] + 1;
        }
        if i >= b && dp[i] < dp[i-b] + 1 {
            dp[i] = dp[i-b] + 1;
        }
        if i >= c && dp[i] < dp[i-c] + 1 {
            dp[i] = dp[i-c] + 1;
        }    
    }
    fmt.Println(dp[n])
}

