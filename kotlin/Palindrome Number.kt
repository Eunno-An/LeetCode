
//여러가지 해결방법이 존재한다.
class Solution {
    //내가 짠 방법
    fun isPalindrome(x: Int): Boolean {
        if(x < 0)
            return false
        val str = x.toString()
        var s=0
        var e=str.length-1
        while(s<=e){
            if(str[s] != str[e])
                return false;
            s++
            e--
        }
        return true
    }
    
    //when 문법 !!
    fun isPalindrome(x: Int): Boolean{
      when{
        x < 0 -> return false
        x < 10 -> return true
      }
      val digitList = breakNumberIntoDigitsList(x)
      return isDigitListPalindrome(digitList)
    }
    fun isPalindromeEasy(x: Int): Boolean{
        val xStr = x.toString()
        return xString == xString.reversed()
    }
    private fun breakNumberIntoDigitsList(num: Int): List<Int>{
        //mutableListOf<Int>()
        val digitList = mutableListOf<Int>()
        var remaining = num
        while(remaining > 0){
            var lastDigit = remaining % 10
            remaining /= 10
          
            digitList.add(lastDigit)
        }
        return digitList
    }
    
    private fun isDigitListPalindrome(digitList: List<Int>): Boolean{
        var start = 0
        var end = digitList.lastIndex
        while(start < end){
            val startDigit = digitList[start]
            val endDigit = digitList[end]
            if(startDigit == endDigit){
              start++
              end--
            }else{
              return false
            }
            
        }
        return true
    }
}

