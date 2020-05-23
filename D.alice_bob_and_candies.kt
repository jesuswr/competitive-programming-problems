import kotlin.math.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

//  kotlinc hello.kt -include-runtime -d hello.jar
//  java -jar hello.jar < txt.txt 

fun main() {
    var t = readInt()

    for (w in 1..t){
        var n = readInt()

        var arr = readInts()

        var left = 0
        var right = n-1

        var left_prev = 0
        var righ_prev = 0

        var total_left = 0
        var total_right = 0

        var turn = 0

        while( left <= right ){
            turn++
            if ( turn%2 == 1 ){ // left turn
                left_prev = 0
                while ( left <= right ){
                    left_prev += arr[left]
                    left++
                    if ( left_prev > righ_prev ){
                        break
                    }
                }
                total_left += left_prev
            }
            else{ // right turn
                righ_prev = 0
                while ( left <= right ){
                    righ_prev += arr[right]
                    right--
                    if ( left_prev < righ_prev ){
                        break
                    }
                }
                total_right += righ_prev
            }
        }

        println("$turn $total_left $total_right")
    }    
}

