
class Solution {
    fun getMinHeight(root: TreeNode?, h: Int): Int{
        if(root?.left == null && root?.right == null)
            return h+1;
        val ret = 100001
        var minLeft = 100001;
        var minRight = 100001;
        if(root.left != null)
            minLeft = getMinHeight(root.left, h+1)
        if(root.right != null)
            minRight = getMinHeight(root.right, h+1)
        //println(minLeft)
        //println(minRight)
        return minOf(minLeft, minRight);

    }
    fun minDepth(root: TreeNode?): Int {
        if(root == null)
            return 0
        return getMinHeight(root, 0)


    }
}
