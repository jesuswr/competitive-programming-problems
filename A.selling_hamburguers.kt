import kotlin.math.*
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toLong() } // list of ints

//  kotlinc hello.kt -include-runtime -d hello.jar
//  java -jar hello.jar < txt.txt 

fun main() {
    var t = readInt()

    for (q in 1..t){
        var n = readInt()
        var arr = readInts()
        var ans = 0.toLong()
        for(i in 0..n-1){
            var sm = 0.toLong()
            var curr = arr[i]
            for(j in 0..n-1){
                if (arr[j] >= curr){
                    sm = sm + curr;
                }
            }
            if (sm > ans){
                ans = sm;
            }
        }
        println(ans)
    }
}