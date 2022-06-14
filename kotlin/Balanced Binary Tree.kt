//when 문장은 참 좋은거 같다
//그리고 maxOf 사용을 알아놓자!
//max는 kotlin.max에 존재하고
//maxOf는 kotlin.comparison에 존재한다!
class Solution {
    fun checkDepth(root: TreeNode?): Int{
        root ?: return 0
        val lH = checkDepth(root.left)
        val rH = checkDepth(root.right)
        val delta = Math.abs(lH - rH)
        return when{
            lH == -1 || rH == -1 || delta > 1 -> -1
            else -> 1 + maxOf(lH, rH)


        }
    }

    fun isBalanced(root: TreeNode?): Boolean {
        return checkDepth(root) != -1

    }
}
