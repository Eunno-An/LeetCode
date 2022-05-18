class Solution {
    fun romanToInt(s: String): Int {
        var ans = 0

        //indices: IntRage타입의 값 반환. s의 최소 인덱스에서 최대 인덱스 반환한다.
        for(i in s.indices){
            val char = s[i]
            val curr = char.num()
            ans += curr
            if(i == 0) continue

            val prev = s[i-1].num()
            if(prev < curr)
                ans -= 2*prev

        }
        return ans
    }

    private fun Char.num() : Int{
        return when(this){
            'M' -> 1000
            'D' -> 500
            'C' -> 100
            'L' -> 50
            'X' -> 10
            'V' -> 5
            'I' -> 1
            else -> 0
        }
    }
}
