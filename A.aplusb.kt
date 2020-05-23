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
        var (x1,x2) = readInts()

        println("${x1 + x2}")
    }
}