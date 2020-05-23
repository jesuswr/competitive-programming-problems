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
        var (x3,x4) = readInts()

        if ( x1 == x3 && x2 + x4 == x1 ){
        	println("Yes")
        }
        else if ( x1 == x4 && x2 + x3 == x1 ){
        	println("Yes")
        }
        else if ( x2 == x3 && x1 + x4 == x2 ){
        	println("Yes")
        }
        else if ( x2 == x4 && x1 + x3 == x2 ){
        	println("Yes")
        }
        else{
        	println("No")
        }
    }
}