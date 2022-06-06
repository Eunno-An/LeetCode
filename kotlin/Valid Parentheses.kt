class Solution {
    fun isValid(s: String): Boolean {
        val bucket = Stack<Char>()//Stack 사용 방법!
        for(i in s.indices){
            val c = s[i]
            if(bucket.empty()){
                bucket.push(c);
                continue;
            }
            if(bucket.last() == '(' && c == ')'
                || bucket.last() == '[' && c == ']'
                || bucket.last() == '{' && c == '}')
                bucket.pop()
            else
                bucket.push(c);
        }
        return bucket.empty()

    }

}

//좀 더 코틀린스타일 코드
//poll() = c++의 top()과 비슷하지만 pop()도 같이 수행한다.
class Solution {
    fun isValid(s: String): Boolean {
    val stack = ArrayDeque<Char>()
    s.forEach {
        when(it) {
            '(', '[', '{' -> stack.push(it)
            ')' -> if (stack.poll() != '(') return false
            '}' -> if (stack.poll() != '{') return false
            ']' -> if (stack.poll() != '[') return false
            }
        }
    
        return stack.isEmpty()
    }
}
