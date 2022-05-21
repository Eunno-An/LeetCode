1차 22-04-10
Time: 4분
Success
Details 
Runtime: 15 ms, faster than 37.31% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 18.9 MB, less than 56.01% of C++ online submissions for Maximum Depth of Binary Tree.
    
2차 22-05-21
Time: 1분
Success
Details
Runtime: 4 ms, faster than 95.26% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 18.9 MB, less than 14.39% of C++ online submissions for Maximum Depth of Binary Tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    문제:
    이진트리의 root가 주어지면, maximum depth를 구하여라.
    
    제한:
    
    해결방법:
    leftSubTree의 maxH와 rightSubTree의 maxH를 구해서 비교재귀
    */
    int findMaxDepth(TreeNode* root, int nowH){
        if(root == NULL)
            return nowH;
        int ret = -1;
        int leftMaxH = findMaxDepth(root->left, nowH + 1);
        int rightMaxH = findMaxDepth(root->right, nowH + 1);
        ret = max(ret, max(leftMaxH, rightMaxH));
        return ret;
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return findMaxDepth(root, 0);
    }
};

//2차 코드
class Solution {
public:
    int maxDepth(TreeNode* root, int height = 0) {
        if(root == NULL)
            return height;
        return max(maxDepth(root->left, height+1), maxDepth(root->right, height+1));
    }
};
