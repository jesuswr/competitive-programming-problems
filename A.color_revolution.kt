import kotlin.math.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

//  kotlinc hello.kt -include-runtime -d hello.jar
//  java -jar hello.jar < txt.txt 

fun main() {
    var t = readInt()

    for (i in 1..t){
        var (n,k) = readInts()

        var den = 1 + k + k*k + k*k*k
        var n1 = n/den
        var n2 = n1*k
        var n3 = n2*k
        var n4 = n3*k
        println("$n1 $n2 $n3 $n4")
    }    
}