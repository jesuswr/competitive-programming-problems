import kotlin.math.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toLong() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toLong() } // list of ints

//  kotlinc hello.kt -include-runtime -d hello.jar
//  java -jar hello.jar < txt.txt 

fun main() {
    var t = readInt()

    for (i in 1..t){
        var (x,y) = readInts()
        var k: Long = 0
        var cnt: Long = 0
        while(k < y){
            if (x <= (y-k)){
                var aux: Long = 1;
                while(x * aux * 10 <= (y-k)){
                    aux = aux * 10
                }
                cnt = cnt + 1
                k = k + aux * x
            }
            else{
                cnt += y - k
                k = y
            }
        }
        println("$cnt")
    }
}