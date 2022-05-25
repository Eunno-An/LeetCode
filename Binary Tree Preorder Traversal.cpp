1차 22-05-25
Time: 2분
Success
Details 
Runtime: 6 ms, faster than 16.98% of C++ online submissions for Binary Tree Preorder Traversal.
Memory Usage: 8.5 MB, less than 16.62% of C++ online submissions for Binary Tree Preorder Traversal.
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
    이진 트리의 root가 주어지면, 전위 순회한 노드 결과를 리턴해라.
    
    제한:
    
    해결방법:
    
    */
    vector<int> ret;
    void preTrav(TreeNode* root){
        if(root == NULL)
            return;
        ret.push_back(root->val);
        preTrav(root->left);
        preTrav(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preTrav(root);
        return ret;
    }
};
