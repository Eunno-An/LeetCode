//22-05-18
//요번껀 내가 풀었다 ㅇ ㅎㅎ
//코틀린 별거 없네!! 라고 하기엔 내가 짠 코드와 다른 사람의 코드를 비교하면... 난 너무 부족!
import kotlin.math.min // java의 math.min으로 하면 안됨!!


class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        var ret = strs[0]
        for(idx in strs.indices){
            if(idx == 0)
                continue
            val temp = strs[idx]

            val minSize = min(ret.length, temp.length)
            var temp2 = ""
            if(minSize == 0) {
                ret = ""
                break
            }
            for(idx2 in 0..minSize-1) {
                if (temp[idx2] != ret[idx2])
                    break
                temp2 += ret[idx2]
            }
            ret = temp2
        }
        return ret
    }
}

//다른 사람 코드
class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        
        if(strs.size == 0) return ""
        
        val commonPrefixBuilder = StringBuilder()
        
        var currIndex = 0
        while(true) {
            strs.mapIndexed { index, str ->
        
            if (currIndex >= str.length || index != 0 && strs[index][currIndex] != strs[index-1][currIndex] ) {
                
                return commonPrefixBuilder.toString()
            }
            
                if (index == strs.size-1) {
                    
                    commonPrefixBuilder.append(str[currIndex])
                    currIndex++
                }
            }
        }
        return commonPrefixBuilder.toString()
    }
}
