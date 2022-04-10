class Solution {
    /*
    * 코틀린은 기본적으로 값이 null이 아니다. 기본적으로는 NotNull이다.
    * Nullable 표현에만 '?'가 사용된다.
    *
    * null을 처리하는 방법 중에 엘비스 연산자(?:)가 있다.
    * p1?.`val` ?: 0 의 뜻은 nullable일수 있는 p1의 val이란 변수가 null일 경우 0으로 대체한다 라는 뜻이다.
    * 참고: https://ddolcat.tistory.com/618
    * */
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        val fakeHead = ListNode(0)
        var cur = fakeHead
        var p1 = l1
        var p2 = l2
        var carry = 0
        while(p1 != null || p2 != null || carry != 0){
            val curSum = (p1?.`val` ?: 0) + (p2?.`val` ?: 0) + carry
            carry = curSum / 10
            cur.next = ListNode(curSum % 10)
            cur = cur.next!!
            p1 = p1?.next
            p2 = p2?.next
        }
        return fakeHead.next
    }
}
