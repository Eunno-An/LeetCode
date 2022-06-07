/*
혼자 힘으로 풀긴 풀었음.
nums.sliceArray(IntRange(start, endInclusive))
->nums를 slice하는데, [start, endInclusive]범위의 IntRange 요소들로 구성되어 있다.
*/
class Solution {
    fun sortedArrayToBST(nums: IntArray): TreeNode? {
        if(nums.isEmpty())
            return null
        val mid = nums.size/2;
        val root = TreeNode(nums[mid])
        root.left = sortedArrayToBST(nums.sliceArray(IntRange(0, mid-1)))
        root.right = sortedArrayToBST(nums.sliceArray(IntRange(mid+1, nums.size-1)))
        return root
    }
}

//다른 Discussion 코드들
fun sortedArrayToBST(nums: IntArray, low: Int = 0, high: Int = nums.size - 1): TreeNode? {
        if (low > high) return null

        val mid = (high + low) / 2
        return TreeNode(nums[mid]).apply{
            left = sortedArrayToBST(nums, low, mid - 1)
            right = sortedArrayToBST(nums, mid + 1, high)
        }
}
