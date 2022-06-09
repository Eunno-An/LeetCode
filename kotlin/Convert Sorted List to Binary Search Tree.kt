2차 22-06-09
회고: 아이디어 떠올리는데 성공. 자세한 구현도 해봄. 그러나 구현에서 실패함
아래 코드는 Discussion에서 퍼온 것.

🎈내 풀이
1)기존에 내가 구현했던 코드는 turtle & hale이라는, 리스트의 중간을 찾아내는 알고리즘으로 리스트의 중간을 찾아냈었음.
2)그래서 각각 리스트의 처음과 중간, 중간과 끝을 매개변수로 주어서 재귀로 할려고 했음

🎈알아야 할 점
NUll 체크 할 때, 어떤건 !!을 쓰고, 어떤건 ?을 쓰고, 어떤건 ?:을 쓴다??
이슈에 첨부하겠음.

fun sortedListToBST(head: ListNode?): TreeNode? {
        val N = size(head) // size of LL
        if (N == 0) return null
        if (N == 1) return TreeNode(head!!.`val`)
        val A = IntArray(N) // LL data in array
        populate(A, head) // fill the array
        return construct(head, A, 0, N - 1)
    }
    
    private fun construct(head: ListNode?, A: IntArray, start: Int, end: Int): TreeNode? {
        if (start > end) return null
        val mid = (start + end) / 2
        val root = TreeNode(A[mid])
        root.left = construct(head, A, start, mid - 1)
        root.right = construct(head, A, mid + 1, end)
        return root
    }
    
    private fun size(head: ListNode?): Int {
        if (head == null) return 0
        if (head.next == null) return 1
        var ans = 0
        var node = head
        while (node != null) {
            ans++
            node = node.next
        }
        return ans
    }
    
    private fun populate(A: IntArray, head: ListNode?) {
        var node = head
        for (i in A.indices) {
            A[i] = node!!.`val`
            node = node?.next
        }
    }
