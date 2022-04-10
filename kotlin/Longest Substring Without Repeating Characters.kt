
/* 2022-04-10 
        * 코틀린 Collection
        * 변수 타입과 동일하게 불변(immutable)과 가변(mutable)이 존재. 기본 Collection은 읽기만 가능.
        * mutableCollection은 읽기 쓰기 둘다 가능.
        * -읽기전용: listOf, setOf, mapOf
        * -수정가능: mutableListOf, mutableSetOf, mutableMapOf
        * mutableMapOf에서는 arrayListOf, hashSetOf, sortedSetOf, linkedSetOf, hashMapOf, linkedMapOf, sortedMapOf 가 있다.
        *
        * collection도 null처리를 할 수 있다.
        * List<String>: List와 String 원소가 null이 될 수 없다.
        * List<String?>: List는 null이 될 수 없지만 String 원소는 null이 될 수 있다.
        * List<String>?: List는 null이 될 수 있지만, String원소는 null이 될 수 없다.
        * List<String?>?: List, String 원소 둘 다 null이 될 수 있다.
        *
        * 그리고 forEachIndexed는 inline function이다. 여기 나와있다. https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/for-each-indexed.html
        *
        * coerceAtLeast()에 대해서...
        * 참고문서: https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.ranges/coerce-at-least.html
        * println(10.coerceAtLeast(5)) // 10
        * println(10.coerceAtLeast(20)) // 20
        * 즉, T.coerceAtLeast(X)는 X가 더 크면 X를 리턴하고, T가 더 크면 T를 리턴한다.
        * 이 문제에서는 만약 a가 기존에 없었을 경우, prevIndex는 null이고
        * a가 한번 더 등장하면 prevIndex는 null이 아니게 되고,
        * startAfterIndex는 prevIndex로 바뀌게 된다.(기존에 a가 있었던 위치)
        * abca면 index = 3, startAfterIndex = 0이 되어 maxLength가 3으로 갱신된다.
        * */
class Solution {
    fun lengthOfLongestSubstring(s: String): Int {
        val visited = hashMapOf<Char, Int>()
        var maxLength = 0
        var startAfterIndex = -1
        s.forEachIndexed{ index, char ->
            val prevIndex: Int? = visited.put(char, index)
            //println({prevIndex == null }.toString())
            //ensures that startAfterIndex is not less than the prevIndex
            if(prevIndex != null)
                startAfterIndex = startAfterIndex.coerceAtLeast(prevIndex)

            maxLength = maxLength.coerceAtLeast(index - startAfterIndex)

        }
        return maxLength
    }
}
