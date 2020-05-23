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
        var n = readInt()

        var auxn = n
        var s = 0

        while( auxn > 0 ){
            if ( (auxn % 10) != 0 ){
                s++
            }
            auxn = auxn/10
        }

        println("$s")

        var m = 1
        while( n > 0 ){
            if ( n %10 != 0 ){
                print("${(n%10)*m} ")
            }
            m = m*10
            n = n/10
        }
        println()
    }    
}