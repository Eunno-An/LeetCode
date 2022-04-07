1차 22-04-07 Fail.
회고
-> 범위를 탐색해가며 한다는 생각은 맞았으나... 왜 자꾸 복잡하게 생각해서 문제를 틀리는지 모르겠다.
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
    bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
        if(root == NULL)
            return true;
        if(minVal >= root->val || root->val >= maxVal) return false;
        return isValidBST(root->left, minVal, root->val) 
            and isValidBST(root->right, root->val, maxVal);
    }
};
