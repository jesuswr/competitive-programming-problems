import kotlin.math.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

//  kotlinc hello.kt -include-runtime -d hello.jar
//  java -jar hello.jar < txt.txt 

fun main() {
    var t = readInt()

    for (q in 1..t){
        var n = readInt()
        if ( n == 1 ){
            println("1")
        }
        else if ( n == 2 || n == 3){
            println("-1")
        }
        else{
            var arr = IntArray(2000)
            arr[1000] = 2
            arr[1001] = 4
            arr[1002] = 1
            arr[1003] = 3
            var l = 999
            var r = 1004
            for(i in 5..n){
                if ( i % 2 == 1 ){
                    arr[l] = i
                    l--
                }
                else{
                    arr[r] = i
                    r++
                }
            }
            for(i in l+1..r-1){
                print("${arr[i]} ")
            }
            println()
        }
    }
}