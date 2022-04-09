1차 22-04-09 Fail
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
    symmetric한지 아닌지를 리턴해라!
    거울이 가운데 있다고 생각하고 좌우가 같아야 한다.
    
    회고
    ->p와 q가 null일 때 어떻게 처리를 해주어야 할 지를 정하지 못했음. 
    */
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSymmetricTest(root->left, root->right);
    }
    
    bool isSymmetricTest(TreeNode* p, TreeNode* q){
        if(p == NULL and q == NULL)
            return true;
        else if(p == NULL || q == NULL)
            return false;
        else if(p->val != q->val)
            return false;
        return isSymmetricTest(p->left, q->right) and 
            isSymmetricTest(p->right, q->left);
    }
};
