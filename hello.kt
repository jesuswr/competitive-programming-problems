import kotlin.math.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var (x1,x2,x3,x4) = readInts()

    var mx = max( max(x1,x2) , max(x3,x4) )

    if ( mx == x1 ){
    	println("${mx - x2} ${mx - x3} ${mx - x4}")
    }
    else if ( mx == x2 ){
    	println("${x2 - x1} ${x2 - x3} ${x2 - x4}")
    }
    else if ( mx == x3 ){
    	println("${x3 - x2} ${x3 - x1} ${x3 - x4}")
    }
    else{
    	println("${x4 - x2} ${x4 - x3} ${x4 - x1}")
    }
}