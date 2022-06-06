//기본 재귀 해법
class Solution {
    fun mergeTwoLists(list1: ListNode?, list2: ListNode?): ListNode? {
        if(list1 == null )
            return list2
        if(list2 == null)
            return list1
        if(list1.`val` < list2.`val`){
            list1.next = mergeTwoLists(list1.next, list2)
            return list1
        }
        list2.next = mergeTwoLists(list2.next, list1)
        return list2
    }
}

//이건 기본 풀인데 배울게 많아서 가져옴.
//!! operator: NPE(Null-Pointer-Exception) 발생시키는 operator. 참고: https://kotlinlang.org/docs/null-safety.html#the-operator
class Solution {
    fun mergeTwoLists(list1: ListNode?, list2: ListNode?): ListNode? {
        if(list1 == null && list2 == null){return null}
        if(list1 == null && list2 != null){return list2}
        if(list1 != null && list2 == null){return list1}
        
        var next1 = list1
        var next2 = list2
        var firstVal: Int
        
        if(next1!!.`val` >= next2!!.`val`){
            firstVal = next2?.`val`
            next2 = next2.next
        }else{
            firstVal = next1?.`val`
            next1 = next1.next
        }
        
        var next3 = ListNode(firstVal)
        var list3Start = next3

        while (next1!= null || next2!= null){
            if(next1== null){
                next3.next = next2
                break
            }
            if(next2== null){
                next3.next = next1
                break
            }
            if(next1!!.`val` >= next2!!.`val`){
                next3.next = ListNode(next2?.`val`)
                next3 = next3.next
                next2 = next2.next
            }else{
                next3.next = ListNode(next1?.`val`)
                next3 = next3.next
                next1 = next1.next 
            }
        }        
        
        return list3Start
    }
}
